#pragma once

#include <Qt3DCore/QTransform>

class ObjectD : public QObject
{
    Q_OBJECT
public:
    ObjectD();
    ~ObjectD();

    QMatrix4x4& toModelMatrix();
    Qt3DCore::QTransform* getTransform() { return m_trans; }
private:
    Qt3DCore::QTransform* m_trans;
    QMatrix4x4 m_modelMatrix;
};

