#include "ShaderProgram.h"


static const char *fragmentShaderSourceCore =
"#version 330\n"
"vec3 lightdir;\n"
"in vec3 worldpos; \n"
"in vec3 worldnormal; \n"
"out vec4 fColor;\n"
"void main(){\n"
"lightdir = normalize(vec3(-1,-1,1));\n"
"vec3 L = -lightdir;\n"
"vec3 N = worldnormal;\n"
"fColor = vec4(dot(L,N),1);\n"
"}\n";

static const char *vertexShaderSourceCore =
"#version 330 core\n"
"layout(location = 0)in vec3 vertex;\n"
"layout(location = 1)in vec3 normal;\n"
"in vec2 uv;\n"
"out vec3 worldpos;\n"
"out vec3 worldnormal;\n"
"uniform mat4 MVP;\n"
"uniform mat4 ModelViewMatrix;\n"
"void main() {\n"
"   worldpos = (ModelViewMatrix * vec4(vertex,1)).xyz;\n"
"   worldnormal = (ModelViewMatrix * vec4(normal,0)).xyz;\n"
"   gl_Position = MVP* vec4(vertex,1);\n"
"}\n";

ShaderProgram::ShaderProgram()
    :m_shader(new QOpenGLShaderProgram)
{
}


ShaderProgram::~ShaderProgram()
{
}

void ShaderProgram::setVertexShader(const QString& vertexShader)
{
    if (!m_shader->addCacheableShaderFromSourceFile(QOpenGLShader::Vertex, vertexShader))
        qCritical() << "Could not compile vertex shader. Log : " << m_shader->log();
    
}


void ShaderProgram::setFragShader(const QString& fragmentShader)
{
    if (!m_shader->addCacheableShaderFromSourceFile(QOpenGLShader::Fragment, fragmentShader))
        qCritical() << "Could not compile Fragment shader. Log : " << m_shader->log();
    
}

void ShaderProgram::setVertexShaderCode()
{
    m_shader->addCacheableShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSourceCore);
}

void ShaderProgram::setFragShaderCode()
{
    m_shader->addCacheableShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSourceCore);
}

void ShaderProgram::setShader(const QSharedPointer<QOpenGLShaderProgram>& shader)
{
    m_shader = shader;
}
