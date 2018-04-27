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
    QString getMaterial();
    QPointF getPoint(int index);

    void setPoints(QList<QPointF> points);
    void setStrokeColor(QColor color);
    void setFillColor(QColor color);
    void setMaterial(QString material);
    void setMaterial(int index);

    void addPoint(QPointF point);
    void addPoint(double x, double y);

    enum Materials {wood, metal, brass, bronze, steel, concrete, reinforced_concrete, stone, granite, sandstone, masonry, brick, plastic, soil, glass};
    const QList<QString> materials_to_numbers_ = * new QList<QString> << "wood" << "metal" << "brass" << "bronze" << "steel" << "concrete" << "reinforced_concrete"
                                                                      << "stone" << "granite" << "sandstone" << "masonry" << "brick" << "plastic" << "soil" << "glass";

private:
    QList<QPointF> points_;
    QColor stroke_;
    QColor fill_;
    Materials material_;
};

#endif // OBJECT_H
