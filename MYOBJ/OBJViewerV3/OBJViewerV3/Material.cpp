#include "Material.h"


Material::Material(const QString& name)
    : m_name(name),
      m_ambient(Qt::black),
      m_diffuse(Qt::white),
      m_specular(Qt::black),
      m_emissive(Qt::white),
      m_shininess(1.0f)
{
}


Material::~Material()
{
}
