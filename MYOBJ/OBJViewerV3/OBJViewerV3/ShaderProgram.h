#pragma once

#include <QOpenGLShaderProgram>
#include <QSharedPointer>

class ShaderProgram
{
public:
    ShaderProgram();
    ~ShaderProgram();

    void setVertexShader(const QString& vertexShader);
    void setFragShader(const QString& fragmentShader);

    void setVertexShaderCode();
    void setFragShaderCode();

    void setShader(const QSharedPointer<QOpenGLShaderProgram>& shader);
    QSharedPointer<QOpenGLShaderProgram> getShader() const { return m_shader; }

private:
    QSharedPointer<QOpenGLShaderProgram> m_shader;
};


typedef QSharedPointer<ShaderProgram> ShaderProgPtr;

