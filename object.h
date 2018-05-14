#ifndef OBJECT_H
#define OBJECT_H

#include <QList>
#include <QString>
#include <QPointF>
#include <QColor>

class Object
{
public:
    enum class Materials {wood, metal, brass, bronze, steel, concrete, reinforced_concrete, stone, granite, sandstone, masonry, brick, plastic, soil, glass};

protected:
    Object();
    Object(QList<QPointF> points, Materials material);
    Object(QList<QPointF> points, QColor stroke, QColor fill, Materials material);

    QList<QPointF> getPoints();
    QColor getStrokeColor();
    QColor getFillColor();
    //QString getMaterial();
    QPointF getPoint(int index);

    void setPoints(QList<QPointF> points);
    void setStrokeColor(QColor color);
    void setFillColor(QColor color);
    /*
    void setMaterial(QString material);
    void setMaterial(int index);
    */

    void addPoint(QPointF point);
    void addPoint(double x, double y);

private:
    QList<QPointF> points_;
    QColor stroke_;
    QColor fill_;
    Materials material_;
};

#endif // OBJECT_H
