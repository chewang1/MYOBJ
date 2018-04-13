#pragma once
#include <QVector3D>
#include <QString>
#include <QColor>
class Material
{
public:
    Material(const QString& name);
    ~Material();

private:

    QString m_name;

    QColor m_ambient;
    QColor m_diffuse;
    QColor m_specular;
    QColor m_emissive;

    float m_shininess;
    
};

