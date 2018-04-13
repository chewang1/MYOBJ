#pragma once
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QSharedPointer>
#include <QVector>
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"
#include <Material.h>

QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)
QT_FORWARD_DECLARE_CLASS(Material)

struct MeshData
{
    QString name;
    unsigned int numIndices;
    unsigned int baseVertex;
    unsigned int baseIndex;
};


struct ModelData
{
    MeshData meshData;
};
class Model
{
public:
    Model();
    ~Model();

    void buildTriangle();

    void build(QSharedPointer<QOpenGLShaderProgram> program);
    void render();

    QVector<QSharedPointer<ModelData>> loadModel(const QString& filename, const QSharedPointer<QOpenGLShaderProgram>& program);
    MeshData loadMesh(unsigned int index, unsigned int numVertices, unsigned int numIndices, const aiMesh* mesh);

    //get
    QSharedPointer<Material> getMaterial() const { return m_material; }
private:
    void centerMesh();
    void normalizeVertices();
    void buildMeshInBuffer(const aiMesh* mesh);


    QOpenGLVertexArrayObject *m_vao;
    QOpenGLBuffer* m_vbo, *m_ibo;
    QOpenGLBuffer* m_vboNormal;
    QVector<QVector3D> m_vertices_Positions;
    QVector<QVector4D> m_vertices_Colors;
    QVector<QVector2D> m_vertices_TexCoord;
    QVector<QVector3D> m_vertices_Normal;
    QVector<GLushort> m_indices;

    QSharedPointer<QOpenGLShaderProgram> m_shader;
    QSharedPointer<Material> m_material;
};

