#include "ObjectD.h"
#include <QDebug>


ObjectD::ObjectD()
{
    m_trans = new Qt3DCore::QTransform;
}


ObjectD::~ObjectD()
{
    delete m_trans;
}

QMatrix4x4& ObjectD::toModelMatrix()
{
    m_modelMatrix.setToIdentity();
    m_modelMatrix.translate(m_trans->translation());
    m_modelMatrix.rotate(m_trans->rotation());
    m_modelMatrix.scale(m_trans->scale3D());
    return m_modelMatrix;
}

