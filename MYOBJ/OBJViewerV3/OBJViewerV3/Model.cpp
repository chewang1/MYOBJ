#include "Model.h"
#include <QVector3D>
#include <QOpenGLShaderProgram>
#include <QDebug>


Model::Model()
    :m_material(QSharedPointer<Material>::create("Material1"))
{
}


Model::~Model()
{
    m_vbo->destroy();
    m_ibo->destroy();
    m_vboNormal->destroy();

    m_vao->destroy();
}


void Model::buildTriangle()
{
    m_vertices_Positions.push_back(QVector3D(-1.0f, 1.f, -1.0f));
    m_vertices_Positions.push_back(QVector3D(-1.0f, -1.0f, -1.0f));
    m_vertices_Positions.push_back(QVector3D(1.0f, -1.0f, -1.0f));

    m_indices.push_back(0);
    m_indices.push_back(1);
    m_indices.push_back(2);
}

void Model::build(QSharedPointer<QOpenGLShaderProgram> program)
{
    m_vao = new QOpenGLVertexArrayObject();
    m_vao->create();
    m_vao->bind();

    m_vbo = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    m_vbo->create();
    m_vbo->bind();
    m_vbo->setUsagePattern(QOpenGLBuffer::StaticDraw);
    m_vbo->allocate(m_vertices_Positions.constData(), m_vertices_Positions.size() * sizeof(QVector3D));

    m_ibo = new QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
    m_ibo->create();
    m_ibo->bind();
    m_ibo->setUsagePattern(QOpenGLBuffer::StaticDraw);
    m_ibo->allocate(m_indices.constData(), m_indices.size() * sizeof(GLshort));

    //normal
    m_vboNormal = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    m_vboNormal->create();
    m_vboNormal->bind();
    m_vboNormal->setUsagePattern(QOpenGLBuffer::StaticDraw);
    m_vboNormal->allocate(m_vertices_Normal.constData(), m_vertices_Normal.size() * sizeof(QVector3D));


    program->bind();
    m_vbo->bind();
    program->enableAttributeArray("vertex");
    program->setAttributeBuffer("vertex", GL_FLOAT, 0, 3);

    m_vboNormal->bind();
    program->enableAttributeArray("normal");
    program->setAttributeBuffer("normal", GL_FLOAT, 0, 3);


    m_vao->release();

}

void Model::render()
{
    m_vao->bind();
    glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_SHORT, nullptr);
    m_vao->release();
}

QVector<QSharedPointer<ModelData>> Model::loadModel(const QString& filename,
    const QSharedPointer<QOpenGLShaderProgram>& program)
{
    m_shader = program;
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(filename.toStdString().c_str(),
        aiProcessPreset_TargetRealtime_MaxQuality |
        aiProcess_FlipUVs);

    QVector<QSharedPointer<ModelData>> model;
    model.resize(scene->mNumMeshes);
    
    //qDebug() << "Model has" << model.size() << "meshes";

    unsigned int numVertices = 0;
    unsigned int numIndices = 0;

    for (unsigned int i = 0; i < model.size(); i++)
    {
        numVertices += scene->mMeshes[i]->mNumVertices;
        numIndices += scene->mMeshes[i]->mNumFaces * 3;
    }
    m_vertices_Positions.reserve(numVertices);
    m_vertices_Normal.reserve(numVertices);
    m_indices.reserve(numIndices);
    
    numVertices = 0;
    numIndices = 0;

    for (unsigned int i = 0; i < model.size(); i++)
    {
        model[i] = QSharedPointer<ModelData>::create();
        model[i]->meshData = loadMesh(i, numVertices, numIndices, scene->mMeshes[i]);
    }
    centerMesh();
    normalizeVertices();
    build(m_shader);
    return model;
}

MeshData Model::loadMesh(unsigned index, unsigned numVertices, unsigned numIndices, const aiMesh* mesh)
{
    MeshData data = MeshData();

    if (mesh->mName.length > 0)
        data.name = QString::fromStdString(mesh->mName.C_Str());
    else
        data.name = "mesh_" + QString::number(index);

    data.numIndices = mesh->mNumFaces * 3;
    data.baseVertex = numVertices;
    data.baseIndex = numIndices;

    buildMeshInBuffer(mesh);

    return data;
}

void Model::centerMesh()
{
    QVector3D center;
    for (auto& i : m_vertices_Positions)
    {
        center += i;
    }
    center /= m_vertices_Positions.size();
    for (auto& i : m_vertices_Positions)
    {
        i += -center;
    }
    //m_center = center;
}

bool IsZero(float num)
{
    return abs(num) < 0.000001f;
}

void Model::normalizeVertices()
{
    QVector3D minimum = m_vertices_Positions[0];
    QVector3D maximum = m_vertices_Positions[0];
    for (auto& vert : m_vertices_Positions)
    {
        float x = vert.x(), y = vert.y(), z = vert.z();
        minimum.setX(std::min(minimum.x(), x));
        minimum.setY(std::min(minimum.y(), y));
        minimum.setZ(std::min(minimum.z(), z));
        maximum.setX(std::max(maximum.x(), x));
        maximum.setY(std::max(maximum.y(), y));
        maximum.setZ(std::max(maximum.z(), z));
    }
    QVector3D extent = maximum - minimum;
    float minExtentLength = 0.f;
    bool xZero = IsZero(extent.x());
    bool yZero = IsZero(extent.y());
    bool zZero = IsZero(extent.z());
    if (xZero && yZero && zZero)
        return; // cannot normalize 1 point mesh
    else if (xZero) // 2 or less may be zero
    {
        if (yZero)
            minExtentLength = extent.z(); // only non-zero
        else if (zZero)
            minExtentLength = extent.y();
        else // only x is zero
            minExtentLength = std::min(extent.y(), extent.z());
    }
    else if (yZero)
    {
        if (xZero)
            minExtentLength = extent.z(); // only non-zero
        else if (zZero)
            minExtentLength = extent.x();
        else // only x is zero
            minExtentLength = std::min(extent.x(), extent.z());
    }
    else if (zZero)
    {
        if (xZero)
            minExtentLength = extent.y(); // only non-zero
        else if (yZero)
            minExtentLength = extent.x();
        else // only x is zero
            minExtentLength = std::min(extent.x(), extent.y());
    }
    else
        minExtentLength = std::min(std::min(extent.x(), extent.y()), extent.z());
    float scalar = 1.f / minExtentLength; // guaranteed to not be 1/0
    for (auto& vert : m_vertices_Positions)
        vert *= scalar;
}

void Model::buildMeshInBuffer(const aiMesh* mesh)
{
    for (unsigned int i = 0; i < mesh->mNumVertices; i++)
    {
        
        m_vertices_Positions.push_back(QVector3D(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z));
        if(mesh->HasNormals())
        {
            QVector3D normal = QVector3D(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z).normalized();
            m_vertices_Normal.push_back(QVector3D(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z));
        }
           
        if (mesh->HasVertexColors(0))
            m_vertices_Colors.push_back(QVector4D(mesh->mColors[0][i].r, mesh->mColors[0][i].g, mesh->mColors[0][i].b, mesh->mColors[0][i].a));
        if (mesh->HasTextureCoords(0))
            m_vertices_TexCoord.push_back(QVector2D(mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y));
    }

    for (unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
        m_indices.push_back(mesh->mFaces[i].mIndices[0]);
        m_indices.push_back(mesh->mFaces[i].mIndices[1]);
        m_indices.push_back(mesh->mFaces[i].mIndices[2]);
    }
}
