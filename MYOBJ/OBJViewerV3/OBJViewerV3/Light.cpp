#include "Light.h"
#include <qmath.h>


const float innerAngle = 30.0f;
const float outerAngle = 40.0f;

Light::Light(const QString& name)
    : m_name(name),
      m_type(PointLight),
      m_position(QVector3D(0, 0, 0)),
      m_direction(QVector3D(0, 0, 1)),
      m_ambient(Qt::black),
      m_diffuse(Qt::white),
      m_specular(Qt::black),
      m_constantAttenuation(1.0f),
      m_linearAttenuation(0.0f),
      m_quadraticAttenuation(0.0f),
      m_spotFalloff(1.0f),
      m_spotInnerAngle(cosf(static_cast<float>(M_PI) * (innerAngle / 180.0f))),
      m_spotOuterAngle(cosf(static_cast<float>(M_PI) * (outerAngle / 180.0f))),
      m_intensity(1.0f)
{
}

Light::~Light()
{
}

void Light::setUniform(QSharedPointer<QOpenGLShaderProgram>& program, const QMatrix4x4& mat)
{

    program->setUniformValue("lighttype", m_type);
    program->setUniformValue("light.intensity", m_intensity);
    program->setUniformValue("light.Ka", m_ambient);
    program->setUniformValue("light.Kd", m_diffuse);
    program->setUniformValue("light.Ks", m_specular);
    
    switch (m_type)
    {
    case PointLight:
        program->setUniformValue("light.position", QVector4D(m_position, 1.f));
        program->setUniformValue("light.constantAttenuation", m_constantAttenuation);
        program->setUniformValue("light.linearAttenuation", m_linearAttenuation);
        program->setUniformValue("light.quadraticAttenuation", m_quadraticAttenuation);
        break;
    case SpotLight:
        program->setUniformValue("light.position", QVector4D(m_position,1.f));
        program->setUniformValue("light.direction", QVector4D(m_direction,0.f));

        program->setUniformValue("light.constantAttenuation", m_constantAttenuation);
        program->setUniformValue("light.linearAttenuation", m_linearAttenuation);
        program->setUniformValue("light.quadraticAttenuation", m_quadraticAttenuation);
                                  
        program->setUniformValue("light.spotFalloff", m_spotFalloff);
        program->setUniformValue("light.spotInnerAngle", m_spotInnerAngle);
        program->setUniformValue("light.spotOuterAngle", m_spotOuterAngle);
        break;
    case DirectionalLight:
        program->setUniformValue("light.direction", QVector4D(m_direction, 0.f));

    }


}

void Light::setLightType(int index)
{
    if (index == 0)
        m_type = Light::DirectionalLight;
    else if (index == 1)
        m_type = LightType::SpotLight;
    else if (index == 2)
        m_type = LightType::PointLight;

    //qDebug() << "LightType is " << m_type << endl;
    //qDebug() << "index is " << index << endl;
}

void Light::setLightpos(const QVector3D& pos)
{
    m_position = pos;
}

void Light::setLightdir(const QVector3D& dir)
{
    m_direction = dir;
}

void Light::setLightAmbient(const QColor& color)
{
    m_ambient = color;
}

void Light::setLightDiffuse(const QColor& color)
{
    m_diffuse = color;
}

void Light::setLightSpecular(const QColor& color)
{
    m_specular = color;
}

void Light::setLightConstantAtten(const float& k0)
{
    m_constantAttenuation = k0;
}

void Light::setLightLinearAtten(const float& k1)
{
    m_linearAttenuation = k1;
}

void Light::setLightQuadraAtten(const float& k2)
{
    m_quadraticAttenuation = k2;
}

void Light::setLightSpotFalloff(const float& s)
{
    m_spotFalloff = s;
}

void Light::setLightInnerAngle(const float& angle)
{
    m_spotInnerAngle = angle;
}

void Light::setLightOuterAngle(const float& angle)
{
    m_spotOuterAngle = angle;
}

void Light::setLightIntensity(const float& i)
{
    m_intensity = i;
}
