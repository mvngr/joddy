#ifndef NATURE_H
#define NATURE_H

#include <object.h>
#include <QList>
#include <QPointF>
#include <QPolygonF>

class Nature : Object
{
public:    
    Nature();
    Nature(QList<QPointF> points);
    void setPolygon(QPolygonF list);
    QPolygonF getPolygon();

    QList<QPointF> getPoints();

private:
    QPolygonF poly_;
};

#endif // NATURE_H
