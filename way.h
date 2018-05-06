#ifndef WAY_H
#define WAY_H

#include <object.h>
#include <QString>
#include <QDebug>
#include <QLine>

class Way : Object
{
public:
    Way();
    Way(QList<QPointF> points);
    QList<QLineF> * getPathLine();
    QList<QPointF> getPoints();

    void setPathLine(QList<QPointF> polygon);

private:
    QList<QLineF> poly_;
};

#endif // WAY_H
