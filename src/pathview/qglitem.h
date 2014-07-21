#ifndef QGLITEM_H
#define QGLITEM_H

#include <QObject>
#include "qglview.h"

class QGLView;

class QGLItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(quint32 modelId READ modelId WRITE setModelId NOTIFY modelIdChanged)
    Q_PROPERTY(QVector3D position READ position WRITE setPosition NOTIFY positionChanged)
    Q_PROPERTY(QVector3D scale READ scale WRITE setScale NOTIFY scaleChanged)
    Q_PROPERTY(QQuaternion rotation READ rotation WRITE setRotation NOTIFY rotationChanged)

public:
    explicit QGLItem(QObject *parent = 0);

    virtual void paint(QGLView *glView) = 0; // must be implemented

    quint32 modelId() const
    {
        return m_modelId;
    }

    QVector3D position() const
    {
        return m_position;
    }

    QVector3D scale() const
    {
        return m_scale;
    }

    QQuaternion rotation() const
    {
        return m_rotation;
    }

signals:
    void modelIdChanged(quint32 arg);
    void positionChanged(QVector3D arg);
    void scaleChanged(QVector3D arg);
    void rotationChanged(QQuaternion arg);

public slots:

    void setModelId(quint32 arg)
    {
        if (m_modelId != arg) {
            m_modelId = arg;
            emit modelIdChanged(arg);
        }
    }

    void setPosition(float x, float y, float z)
    {
        setPosition(QVector3D(x,y,z));
    }

    void setPosition(QVector3D arg)
    {
        if (m_position != arg) {
            m_position = arg;
            emit positionChanged(arg);
        }
    }

    void setScale(float x, float y, float z)
    {
        setScale(QVector3D(x,y,z));
    }

    void setScale(QVector3D arg)
    {
        if (m_scale != arg) {
            m_scale = arg;
            emit scaleChanged(arg);
        }
    }

    void setRotation(float angle, float x, float y, float z)
    {
        setRotation(angle, QVector3D(x,y,z));
    }

    void setRotation(float angle, QVector3D axis)
    {
        setRotation(QQuaternion(angle, axis));
    }

    void setRotation(QQuaternion arg)
    {
        if (m_rotation != arg) {
            m_rotation = arg;
            emit rotationChanged(arg);
        }
    }

private:
    quint32 m_modelId;
    QVector3D m_position;
    QVector3D m_scale;
    QQuaternion m_rotation;
};

#endif // QGLITEM_H