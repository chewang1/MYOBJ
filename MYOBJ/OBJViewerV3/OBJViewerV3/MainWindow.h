#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"

QT_FORWARD_DECLARE_CLASS(GLWidget)
QT_FORWARD_DECLARE_CLASS(Model)

typedef QSharedPointer<ShaderProgram> ShaderProgPtr;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);
    void slotFileDialog();
    void setTabAtt();
    QString getFilename() const { return m_filename; }
    QSharedPointer<Model> getModel() const { return m_model; }

public slots:
    void updateScaleX(double x);
    void updateScaleY(double y);
    void updateScaleZ(double z);
    void updateScale(double number);

    void updateRotateX(double x);
    void updateRotateY(double y);
    void updateRotateZ(double z);

    void updateLightType(int index);
    
    void updateLightDirX(double x);
    void updateLightDirY(double y);
    void updateLightDirZ(double z);

    void updateLightAmbientR(int r);
    void updateLightAmbientG(int g);
    void updateLightAmbientB(int b);
    void updateLightAmbientA(int a);

    void updateLightDiffuseR(int r);
    void updateLightDiffuseG(int g);
    void updateLightDiffuseB(int b);
    void updateLightDiffuseA(int a);

    void updateLightSpecularR(int r);
    void updateLightSpecularG(int g);
    void updateLightSpecularB(int b);
    void updateLightSpecularA(int a);

    void updateLightPosX(double x);
    void updateLightPosY(double y);
    void updateLightPosZ(double z);

    void updateLightIntensity(double i);

    void updateLightFalloff(double f);

    void updateLightInnerAngle(double angle);
    void updateLightOuterAngle(double angle);



private:
    Ui::MainWindowClass ui;
    QString m_filename;
    QSharedPointer<Model> m_model;
    void createAction();
    void initParams();
};
