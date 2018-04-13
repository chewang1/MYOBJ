#include "MainWindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->setCentralWidget(ui.openGLWidget);
    this->setWindowTitle("My OBJ Viewer");
    setTabAtt();
    createAction();
    initParams();
    ui.widget_directionLight->show();
    ui.widget_pointlight->hide();
    ui.widget_spotlight->hide();
}


void MainWindow::slotFileDialog()
{
    m_filename = QFileDialog::getOpenFileName(
                    this,
                    tr("Open OBJ File"),
                    QDir::currentPath(),
                    "OBJ files (*.obj)"
                    );
    //if select nothing or cancel
    if (m_filename == "")
        return;
    ui.openGLWidget->setFilename(m_filename);
    ui.openGLWidget->setIsLoad();
}

void MainWindow::setTabAtt()
{
    ui.tabWidget->tabBar()->setTabTextColor(0, Qt::black);   //transform tab
    ui.tabWidget->tabBar()->setTabTextColor(1, Qt::black);   //light tab
    ui.tabWidget_2->tabBar()->setTabTextColor(0, Qt::black); //material tab
}

void MainWindow::createAction()
{
    ui.actionOpen->setStatusTip("open obj file");
    ui.actionOpen->setShortcut(QKeySequence::Open);
    connect(ui.actionOpen, &QAction::triggered, this, &MainWindow::slotFileDialog);

    ui.actionExit->setStatusTip("Exit the application");
    ui.actionExit->setShortcut(QKeySequence::Quit);
}

void MainWindow::initParams()
{
    //SCALE
    ui.scale_x->setRange(0.1, 10.0);
    ui.scale_y->setRange(0.1, 10.0);
    ui.scale_z->setRange(0.1, 10.0);

    ui.scale_x->setSingleStep(0.1);
    ui.scale_y->setSingleStep(0.1);
    ui.scale_z->setSingleStep(0.1);

    ui.scale_x->setValue(1.0);
    ui.scale_y->setValue(1.0);
    ui.scale_z->setValue(1.0);

    connect(ui.scale_x, SIGNAL(valueChanged(double)), this, SLOT(updateScaleX(double)));
    connect(ui.scale_y, SIGNAL(valueChanged(double)), this, SLOT(updateScaleY(double)));
    connect(ui.scale_z, SIGNAL(valueChanged(double)), this, SLOT(updateScaleZ(double)));

    ui.scale_all->setRange(0.1, 10.0);
    ui.scale_all->setSingleStep(0.1);
    ui.scale_all->setValue(1.0);

    connect(ui.scale_all, SIGNAL(valueChanged(double)), this, SLOT(updateScale(double)));

    //ROTATE

    ui.rotate_x->setRange(-360, 360);
    ui.rotate_y->setRange(-360, 360);
    ui.rotate_z->setRange(-360, 360);

    ui.rotate_x->setSingleStep(1.0);
    ui.rotate_y->setSingleStep(1.0);
    ui.rotate_z->setSingleStep(1.0);

    ui.rotate_x->setValue(0.0);
    ui.rotate_y->setValue(0.0);
    ui.rotate_z->setValue(0.0);

    connect(ui.rotate_x, SIGNAL(valueChanged(double)), this, SLOT(updateRotateX(double)));
    connect(ui.rotate_y, SIGNAL(valueChanged(double)), this, SLOT(updateRotateY(double)));
    connect(ui.rotate_z, SIGNAL(valueChanged(double)), this, SLOT(updateRotateZ(double)));

    //Light tab
    connect(ui.comboBox_light, SIGNAL(currentIndexChanged(int)), this, SLOT(updateLightType(int)));

    //Light Attribute
    if (ui.openGLWidget->getLight().getType() == Light::DirectionalLight)
    {
        connect(ui.lightdir_x, SIGNAL(valueChanged(double)), this, SLOT(updateLightDirX(double)));
        connect(ui.lightdir_y, SIGNAL(valueChanged(double)), this, SLOT(updateLightDirY(double)));
        connect(ui.lightdir_z, SIGNAL(valueChanged(double)), this, SLOT(updateLightDirZ(double)));
    }
    else if(ui.openGLWidget->getLight().getType() == Light::SpotLight)
    {
        connect(ui.lightdir_x_2, SIGNAL(valueChanged(double)), this, SLOT(updateLightDirX(double)));
        connect(ui.lightdir_y_2, SIGNAL(valueChanged(double)), this, SLOT(updateLightDirY(double)));
        connect(ui.lightdir_z_2, SIGNAL(valueChanged(double)), this, SLOT(updateLightDirZ(double)));

        connect(ui.lightpos_x_2, SIGNAL(valueChanged(double)), this, SLOT(updateLightPosX(double)));
        connect(ui.lightpos_y_2, SIGNAL(valueChanged(double)), this, SLOT(updateLightPosY(double)));
        connect(ui.lightpos_z_2, SIGNAL(valueChanged(double)), this, SLOT(updateLightPosZ(double)));
    }
    else if(ui.openGLWidget->getLight().getType() == Light::PointLight)
    {
        connect(ui.lightpos_x_3, SIGNAL(valueChanged(double)), this, SLOT(updateLightPosX(double)));
        connect(ui.lightpos_y_3, SIGNAL(valueChanged(double)), this, SLOT(updateLightPosY(double)));
        connect(ui.lightpos_z_3, SIGNAL(valueChanged(double)), this, SLOT(updateLightPosZ(double)));
    }

    //ambient R
    connect(ui.lightKa_r, SIGNAL(valueChanged(int)), this, SLOT(updateLightAmbientR(int)));
    connect(ui.lightKa_r_2, SIGNAL(valueChanged(int)), this, SLOT(updateLightAmbientR(int)));
    connect(ui.lightKa_r_3, SIGNAL(valueChanged(int)), this, SLOT(updateLightAmbientR(int)));

    connect(ui.lightKa_g, SIGNAL(valueChanged(int)), this, SLOT(updateLightAmbientG(int)));
    connect(ui.lightKa_g_2, SIGNAL(valueChanged(int)), this, SLOT(updateLightAmbientG(int)));
    connect(ui.lightKa_g_3, SIGNAL(valueChanged(int)), this, SLOT(updateLightAmbientG(int)));

    connect(ui.lightKa_b, SIGNAL(valueChanged(int)), this, SLOT(updateLightAmbientB(int)));
    connect(ui.lightKa_b_2, SIGNAL(valueChanged(int)), this, SLOT(updateLightAmbientB(int)));
    connect(ui.lightKa_b_3, SIGNAL(valueChanged(int)), this, SLOT(updateLightAmbientB(int)));
      
    connect(ui.lightKa_a, SIGNAL(valueChanged(int)), this, SLOT(updateLightAmbientA(int)));
    connect(ui.lightKa_a_2, SIGNAL(valueChanged(int)), this, SLOT(updateLightAmbientA(int)));
    connect(ui.lightKa_a_3, SIGNAL(valueChanged(int)), this, SLOT(updateLightAmbientA(int)));

    //diffuse
    connect(ui.lightKd_r, SIGNAL(valueChanged(int)), this, SLOT(updateLightDiffuseR(int)));
    connect(ui.lightKd_r_2, SIGNAL(valueChanged(int)), this, SLOT(updateLightDiffuseR(int)));
    connect(ui.lightKd_r_3, SIGNAL(valueChanged(int)), this, SLOT(updateLightDiffuseR(int)));

    connect(ui.lightKd_g, SIGNAL(valueChanged(int)), this, SLOT(updateLightDiffuseG(int)));
    connect(ui.lightKd_g_2, SIGNAL(valueChanged(int)), this, SLOT(updateLightDiffuseG(int)));
    connect(ui.lightKd_g_3, SIGNAL(valueChanged(int)), this, SLOT(updateLightDiffuseG(int)));
               
    connect(ui.lightKd_b, SIGNAL(valueChanged(int)), this, SLOT(updateLightDiffuseB(int)));
    connect(ui.lightKd_b_2, SIGNAL(valueChanged(int)), this, SLOT(updateLightDiffuseB(int)));
    connect(ui.lightKd_b_3, SIGNAL(valueChanged(int)), this, SLOT(updateLightDiffuseB(int)));
               
    connect(ui.lightKd_a, SIGNAL(valueChanged(int)), this, SLOT(updateLightDiffuseA(int)));
    connect(ui.lightKd_a_2, SIGNAL(valueChanged(int)), this, SLOT(updateLightDiffuseA(int)));
    connect(ui.lightKd_a_3, SIGNAL(valueChanged(int)), this, SLOT(updateLightDiffuseA(int)));
    
    //specluar
    connect(ui.lightKs_r, SIGNAL(valueChanged(int)), this, SLOT(updateLightSpecularR(int)));
    connect(ui.lightKs_r_2, SIGNAL(valueChanged(int)), this, SLOT(updateLightSpecularR(int)));
    connect(ui.lightKs_r_3, SIGNAL(valueChanged(int)), this, SLOT(updateLightSpecularR(int)));
               
    connect(ui.lightKs_g, SIGNAL(valueChanged(int)), this, SLOT(updateLightSpecularG(int)));
    connect(ui.lightKs_g_2, SIGNAL(valueChanged(int)), this, SLOT(updateLightSpecularG(int)));
    connect(ui.lightKs_g_3, SIGNAL(valueChanged(int)), this, SLOT(updateLightSpecularG(int)));
               
    connect(ui.lightKs_b, SIGNAL(valueChanged(int)), this, SLOT(updateLightSpecularB(int)));
    connect(ui.lightKs_b_2, SIGNAL(valueChanged(int)), this, SLOT(updateLightSpecularB(int)));
    connect(ui.lightKs_b_3, SIGNAL(valueChanged(int)), this, SLOT(updateLightSpecularB(int)));
               
    connect(ui.lightKs_a, SIGNAL(valueChanged(int)), this, SLOT(updateLightSpecularA(int)));
    connect(ui.lightKs_a_2, SIGNAL(valueChanged(int)), this, SLOT(updateLightSpecularA(int)));
    connect(ui.lightKs_a_3, SIGNAL(valueChanged(int)), this, SLOT(updateLightSpecularA(int)));

    //angle, intensity, falloff
    connect(ui.lightInten, SIGNAL(valueChanged(double)), this, SLOT(updateLightIntensity(double)));
    connect(ui.lightInten_2, SIGNAL(valueChanged(double)), this, SLOT(updateLightIntensity(double)));
    connect(ui.lightInten_3, SIGNAL(valueChanged(double)), this, SLOT(updateLightIntensity(double)));
    connect(ui.light_inner, SIGNAL(valueChanged(double)), this, SLOT(updateLightInnerAngle(double)));
    connect(ui.light_outer, SIGNAL(valueChanged(double)), this, SLOT(updateLightOuterAngle(double)));


    //k0,k1,k2..
}

void MainWindow::updateScaleX(double x)
{
    float y = ui.openGLWidget->getObject().getTransform()->scale3D().y();
    float z = ui.openGLWidget->getObject().getTransform()->scale3D().z();
    ui.openGLWidget->getObject().getTransform()->setScale3D(QVector3D(x, y, z));
    ui.openGLWidget->getObject().toModelMatrix();
}

void MainWindow::updateScaleY(double y)
{
    float x = ui.openGLWidget->getObject().getTransform()->scale3D().x();
    float z = ui.openGLWidget->getObject().getTransform()->scale3D().z();
    ui.openGLWidget->getObject().getTransform()->setScale3D(QVector3D(x, y, z));
    ui.openGLWidget->getObject().toModelMatrix();
}

void MainWindow::updateScaleZ(double z)
{
    float x = ui.openGLWidget->getObject().getTransform()->scale3D().x();
    float y = ui.openGLWidget->getObject().getTransform()->scale3D().y();
    ui.openGLWidget->getObject().getTransform()->setScale3D(QVector3D(x, y, z));
    ui.openGLWidget->getObject().toModelMatrix();
}

void MainWindow::updateScale(double number)
{
    ui.openGLWidget->getObject().getTransform()->setScale(number);
    ui.openGLWidget->getObject().toModelMatrix();
}

void MainWindow::updateRotateX(double x)
{
    ui.openGLWidget->getObject().getTransform()->setRotationX(x);
    ui.openGLWidget->getObject().toModelMatrix();
    //qDebug() << "UI ROTX: " << ui.rotate_x->value() << endl;
}

void MainWindow::updateRotateY(double y)
{
    ui.openGLWidget->getObject().getTransform()->setRotationY(y);
    ui.openGLWidget->getObject().toModelMatrix();
}

void MainWindow::updateRotateZ(double z)
{
    ui.openGLWidget->getObject().getTransform()->setRotationZ(z);
    ui.openGLWidget->getObject().toModelMatrix();
}

void MainWindow::updateLightType(int index)
{
    
    ui.openGLWidget->getLight().setLightType(index);
    
    switch (index)
    {
    case 0: //direction light
            ui.widget_directionLight->show();
            ui.widget_pointlight->hide();
            ui.widget_spotlight->hide();
        break;
    case 1: //spot light
            ui.widget_directionLight->hide();
            ui.widget_pointlight->hide();
            ui.widget_spotlight->show();
        break;
    case 2: //point light
            ui.widget_directionLight->hide();
            ui.widget_pointlight->show();
            ui.widget_spotlight->hide();
        break;   
    }

    //qDebug() << "direction is " << ui.widget_directionLight->isHidden() << endl;
    //qDebug() << "spot is " << ui.widget_spotlight->isHidden() << endl;
    //qDebug() << "point is " << ui.widget_pointlight->isHidden() << endl;

}

void MainWindow::updateLightDirX(double x)
{
    double y = ui.openGLWidget->getLight().getLightDir().y();
    double z = ui.openGLWidget->getLight().getLightDir().z();
    ui.openGLWidget->getLight().setLightdir(QVector3D(x, y, z));
}

void MainWindow::updateLightDirY(double y)
{
    double x = ui.openGLWidget->getLight().getLightDir().x();
    double z = ui.openGLWidget->getLight().getLightDir().z();
    ui.openGLWidget->getLight().setLightdir(QVector3D(x, y, z));
}

void MainWindow::updateLightDirZ(double z)
{
    double y = ui.openGLWidget->getLight().getLightDir().y();
    double x = ui.openGLWidget->getLight().getLightDir().x();
    ui.openGLWidget->getLight().setLightdir(QVector3D(x, y, z));
}

void MainWindow::updateLightAmbientR(int r)
{
    int g = ui.openGLWidget->getLight().getLightAmbient().green();
    int b = ui.openGLWidget->getLight().getLightAmbient().blue();
    int a = ui.openGLWidget->getLight().getLightAmbient().alpha();
    ui.openGLWidget->getLight().setLightAmbient(QColor(r, g, b, a));
}

void MainWindow::updateLightAmbientG(int g)
{
    int r = ui.openGLWidget->getLight().getLightAmbient().red();
    int b = ui.openGLWidget->getLight().getLightAmbient().blue();
    int a = ui.openGLWidget->getLight().getLightAmbient().alpha();
    ui.openGLWidget->getLight().setLightAmbient(QColor(r, g, b, a));
}

void MainWindow::updateLightAmbientB(int b)
{
    int g = ui.openGLWidget->getLight().getLightAmbient().green();
    int r = ui.openGLWidget->getLight().getLightAmbient().red();
    int a = ui.openGLWidget->getLight().getLightAmbient().alpha();
    ui.openGLWidget->getLight().setLightAmbient(QColor(r, g, b, a));
}

void MainWindow::updateLightAmbientA(int a)
{
    int g = ui.openGLWidget->getLight().getLightAmbient().green();
    int b = ui.openGLWidget->getLight().getLightAmbient().blue();
    int r = ui.openGLWidget->getLight().getLightAmbient().red();
    ui.openGLWidget->getLight().setLightAmbient(QColor(r, g, b, a));
}

void MainWindow::updateLightDiffuseR(int r)
{
    int g = ui.openGLWidget->getLight().getLightDiffuse().green();
    int b = ui.openGLWidget->getLight().getLightDiffuse().blue();
    int a = ui.openGLWidget->getLight().getLightDiffuse().alpha();
    ui.openGLWidget->getLight().setLightAmbient(QColor(r, g, b, a));
}

void MainWindow::updateLightDiffuseG(int g)
{
    int r = ui.openGLWidget->getLight().getLightDiffuse().red();
    int b = ui.openGLWidget->getLight().getLightDiffuse().blue();
    int a = ui.openGLWidget->getLight().getLightDiffuse().alpha();
    ui.openGLWidget->getLight().setLightAmbient(QColor(r, g, b, a));
}

void MainWindow::updateLightDiffuseB(int b)
{
    int g = ui.openGLWidget->getLight().getLightDiffuse().green();
    int r = ui.openGLWidget->getLight().getLightDiffuse().red();
    int a = ui.openGLWidget->getLight().getLightDiffuse().alpha();
    ui.openGLWidget->getLight().setLightAmbient(QColor(r, g, b, a));
}

void MainWindow::updateLightDiffuseA(int a)
{
    int g = ui.openGLWidget->getLight().getLightDiffuse().green();
    int b = ui.openGLWidget->getLight().getLightDiffuse().blue();
    int r = ui.openGLWidget->getLight().getLightDiffuse().red();
    ui.openGLWidget->getLight().setLightAmbient(QColor(r, g, b, a));
}

void MainWindow::updateLightSpecularR(int r)
{
    int g = ui.openGLWidget->getLight().getLightSpecular().green();
    int b = ui.openGLWidget->getLight().getLightSpecular().blue();
    int a = ui.openGLWidget->getLight().getLightSpecular().alpha();
    ui.openGLWidget->getLight().setLightAmbient(QColor(r, g, b, a));
}

void MainWindow::updateLightSpecularG(int g)
{
    int r = ui.openGLWidget->getLight().getLightSpecular().red();
    int b = ui.openGLWidget->getLight().getLightSpecular().blue();
    int a = ui.openGLWidget->getLight().getLightSpecular().alpha();
    ui.openGLWidget->getLight().setLightAmbient(QColor(r, g, b, a));
}

void MainWindow::updateLightSpecularB(int b)
{
    int g = ui.openGLWidget->getLight().getLightSpecular().green();
    int r = ui.openGLWidget->getLight().getLightSpecular().red();
    int a = ui.openGLWidget->getLight().getLightSpecular().alpha();
    ui.openGLWidget->getLight().setLightAmbient(QColor(r, g, b, a));
}

void MainWindow::updateLightSpecularA(int a)
{
    int g = ui.openGLWidget->getLight().getLightSpecular().green();
    int b = ui.openGLWidget->getLight().getLightSpecular().blue();
    int r = ui.openGLWidget->getLight().getLightSpecular().red();
    ui.openGLWidget->getLight().setLightAmbient(QColor(r, g, b, a));
}

void MainWindow::updateLightPosX(double x)
{
    double y = ui.openGLWidget->getLight().getLightPos().y();
    double z = ui.openGLWidget->getLight().getLightPos().z();
    ui.openGLWidget->getLight().setLightpos(QVector3D(x, y, z));
}

void MainWindow::updateLightPosY(double y)
{
    double x = ui.openGLWidget->getLight().getLightPos().x();
    double z = ui.openGLWidget->getLight().getLightPos().z();
    ui.openGLWidget->getLight().setLightpos(QVector3D(x, y, z));
}

void MainWindow::updateLightPosZ(double z)
{
    double y = ui.openGLWidget->getLight().getLightPos().y();
    double x = ui.openGLWidget->getLight().getLightPos().x();
    ui.openGLWidget->getLight().setLightpos(QVector3D(x, y, z));
}

void MainWindow::updateLightIntensity(double i)
{
    ui.openGLWidget->getLight().setLightIntensity(i);
}

void MainWindow::updateLightFalloff(double f)
{
    ui.openGLWidget->getLight().setLightSpotFalloff(f);
}

void MainWindow::updateLightInnerAngle(double angle)
{
    ui.openGLWidget->getLight().setLightInnerAngle(angle);
}

void MainWindow::updateLightOuterAngle(double angle)
{
    ui.openGLWidget->getLight().setLightOuterAngle(angle);
}




