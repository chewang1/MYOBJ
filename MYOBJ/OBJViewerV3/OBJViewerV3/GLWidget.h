#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QMatrix4x4>
#include "ShaderProgram.h"
#include <Qt3DCore>
#include "ObjectD.h"
#include "Light.h"


QT_FORWARD_DECLARE_CLASS(Model)


typedef QSharedPointer<ShaderProgram> ShaderProgPtr;

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = Q_NULLPTR);
    ~GLWidget();

    void setIsLoad() { m_isLoaded = true; }
    void setFilename(QString filename) { m_filename = filename; }

    void checkLoadingEvent();
    //getter
    ObjectD& getObject() { return m_object; }
    Light& getLight() { return m_light; }
private:
    QMatrix4x4 m_projection;
    QSharedPointer<Model> m_model;
    ShaderProgPtr m_shader;

    void prepareShader();

    int m_worldLoc = 0;
    int m_mvpLoc = 0;

    //will replace by Camera class future
    QMatrix4x4  m_camera;
    //model transform matrix
    ObjectD m_object;
    Light m_light;

    bool m_isLoaded = false;
    QString m_filename;
    QPoint m_mouse;
    int m_xRot;
    int m_yRot;
protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;
    void setXRotation(int angle);
    void setYRotation(int angle);
};
