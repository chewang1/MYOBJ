#include "GLWidget.h"
#include "Model.h"
#include <cassert>
#include "ui_MainWindow.h"
GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent),
      m_light("Light1")
{
    /*QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(16);*/
}

GLWidget::~GLWidget()
{
}


void GLWidget::checkLoadingEvent()
{
    if (m_isLoaded)
    {
        m_model = QSharedPointer<Model>::create();
        m_model->loadModel(m_filename, m_shader->getShader());
        m_isLoaded = false;
        m_filename = "";        
    }    
}


void GLWidget::prepareShader()
{
    m_shader = ShaderProgPtr::create();
    //m_shader->setVertexShaderCode();
    //m_shader->setFragShaderCode();
    //m_shader->setVertexShader(":/Resources/shaders/diffuse.vert");
    //m_shader->setFragShader(":/Resources/shaders/diffuse.frag");
    m_shader->setFragShader(":/Resources/shaders/phong.frag");
    m_shader->setVertexShader(":/Resources/shaders/phong.vert");
    m_shader->getShader()->link();
}

void GLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.407f, 0.452f, 0.51f, 0.8f);
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_CULL_FACE);

    //QString filename = R"(C:\Users\CheWang-ROG\Desktop\Qt Projects\OBJViewerV3\OBJViewerV3\Resources\models\cube.obj)";
    
    //handle shader
    prepareShader();
    QSharedPointer<QOpenGLShaderProgram> shader = m_shader->getShader();
    
    shader->bind();
    //get uniform location from shader
    m_mvpLoc = shader->uniformLocation("MVP");
    m_worldLoc = shader->uniformLocation("ModelViewMatrix");
    //set cam matrix
    m_camera.setToIdentity();
    m_camera.translate(0, 0, -5);

    //set light
    m_light.setLightType(Light::LightType::DirectionalLight);
    m_light.setLightAmbient({255,0,0});
    m_light.setLightDiffuse(Qt::white);
    m_light.setLightSpecular(Qt::white);
    m_light.setLightIntensity(1.0f);
    m_light.setLightdir({-1,-1,-1});

}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    checkLoadingEvent();
    
    if (m_model != nullptr)
    {
        QMatrix4x4 worldm = m_object.toModelMatrix();
        QMatrix4x4 modelviewm = m_camera * worldm;
        QSharedPointer<QOpenGLShaderProgram> shader = m_shader->getShader();
        shader->bind();
        shader->setUniformValue(m_mvpLoc, m_projection * modelviewm);
        shader->setUniformValue(m_worldLoc, modelviewm);
        shader->setUniformValue("modelMatrix", worldm);
        m_model->render();
        m_light.setUniform(shader, modelviewm);
        this->update();
    }
}

void GLWidget::resizeGL(int w, int h)
{
    qreal aspect = qreal(w) / qreal(h ? h : 1);
    const qreal zNear = 0.01f, Zfar = 100.0, fov = 45.0;
    m_projection.setToIdentity();
    m_projection.perspective(fov, aspect, zNear, Zfar);
}

void GLWidget::mousePressEvent(QMouseEvent* event)
{
    m_mouse = event->pos();
}
static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360 * 16)
        angle -= 360 * 16;
}
void GLWidget::mouseMoveEvent(QMouseEvent* event)
{
    int dx = event->x() - m_mouse.x();
    int dy = event->y() - m_mouse.y();

    if(event->buttons() & Qt::LeftButton)
    {
        setXRotation(m_xRot + dy);
        setYRotation(m_yRot + dx);
        m_object.getTransform()->setRotationX(m_xRot);
        m_object.getTransform()->setRotationY(m_yRot);
       /* m_ui->rotate_x->setValue(3 * dy);
        m_ui->rotate_y->setValue(3 * dx);*/
    }
    
    m_mouse = event->pos();
}

void GLWidget::keyPressEvent(QKeyEvent* event)
{
}

void GLWidget::keyReleaseEvent(QKeyEvent* event)
{
}



void GLWidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_xRot) {
        m_xRot = angle;
        //update();
    }
}

void GLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_yRot) {
        m_yRot = angle;
        //update();
    }
}
