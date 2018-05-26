#ifndef NATURE_H
#define NATURE_H

#include <object.h>
#include <QList>
#include <QPointF>
#include <QPolygonF>

class Nature : Object
{
public:    
    enum class Landuse{allotments, basin, brownfield, cemetery, commercial, conservation, construction, depot, farmland, farmyard, forest, garages, grass, greenfield,
                       greenhouse_horticulture, industrial, landfill, meadow, military, orchard, pasture, peat_cutting, plant_nursery, port, quarry, railway, recreation_ground,
                      religious, reservoir, residential, retail, salt_pond, village_green, vineyard};
    Nature();
    Nature(QList<QPointF> points);
    Nature(QList<QPointF> points, Landuse landuse);
    void setPolygon(QPolygonF list);
    void setLanduse(Landuse landuse);

    QPolygonF getPolygon();
    Landuse getLanduse();

    QList<QPointF> getPoints();

private:
    Landuse landuse_;
    QPolygonF poly_;
};

#endif // NATURE_H
