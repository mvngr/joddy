#ifndef WAY_H
#define WAY_H

#include <object.h>
#include <QString>
#include <QDebug>
#include <QPolygon>

class Way : Object
{
public:
    Way();
    Way(QList<QPointF> points);
    QPolygonF getPolygon();
    QList<QPointF> getPoints();

    void setPolygon(QPolygonF polygon);

private:
    QPolygonF poly_;
};

#endif // WAY_H
