#pragma once
#include <QString>
#include <QVector3D>
#include <QColor>
#include <QOpenGLShaderProgram>

class Light
{
public:
    enum LightType
    {
        DirectionalLight = 0,
        SpotLight,
        PointLight    
    };


    Light(const QString& name);
    ~Light();

    void setUniform(QSharedPointer<QOpenGLShaderProgram> &program, const QMatrix4x4& mat);
    
    //setter
    void setLightType(int index);

    void setLightpos(const QVector3D& pos);
    void setLightdir(const QVector3D& dir);
    void setLightAmbient(const QColor& color);
    void setLightDiffuse(const QColor& color);
    void setLightSpecular(const QColor& color);
    void setLightConstantAtten(const float& k0);
    void setLightLinearAtten(const float& k1);
    void setLightQuadraAtten(const float& k2);
    void setLightSpotFalloff(const float& s);
    void setLightInnerAngle(const float& angle);
    void setLightOuterAngle(const float& angle);
    void setLightIntensity(const float& i);
    //getter
    LightType getType() const { return  m_type; }
    QVector3D getLightDir() const { return m_direction; }
    QColor getLightAmbient() const { return m_ambient; }
    QColor getLightDiffuse() const { return m_diffuse; }
    QColor getLightSpecular() const { return m_specular; }
    QVector3D getLightPos() const { return m_position; }
private:

    QString m_name;
    LightType m_type;

    QVector3D m_position;
    QVector3D m_direction;

    QColor m_ambient;
    QColor m_diffuse;
    QColor m_specular;

    float m_constantAttenuation;  //K0
    float m_linearAttenuation;    //k1
    float m_quadraticAttenuation; //k2

    float m_spotFalloff;
    float m_spotInnerAngle;
    float m_spotOuterAngle;
    float m_intensity;

};

