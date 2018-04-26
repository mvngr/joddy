#ifndef OBJECT_H
#define OBJECT_H

#include <QList>
#include <QString>
#include <QPointF>
#include <QColor>

class Object
{
protected:
    Object();
    Object(QList<QPointF> points);
    Object(QList<QPointF> points, QColor stroke, QColor fill);

    QList<QPointF> getPoints();
    QColor getStrokeColor();
    QColor getFillColor();

    void setPoints(QList<QPointF> points);
    void setStrokeColor(QColor color);
    void setFillColor(QColor color);

    enum Materials {wood, metal, brass, bronze, steel, concrete, reinforced_concrete,
                    stone, granite, sandstone, masonry, brick, plastic, soil, glass};

private:
    QList<QPointF> points_;
    QColor stroke_;
    QColor fill_;
};

#endif // OBJECT_H
