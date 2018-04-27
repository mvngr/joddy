#ifndef BUILDING_H
#define BUILDING_H

#include <object.h>
#include <QDebug>

class Building : Object
{
public:
    Building();
    Building(QList<QPointF> points);
    Building(QList<QPointF> points, QColor stroke, QColor fill);

    QString getStreetName();
    QString getNumber();
    int getLevels();
    QString getType();
    QString getMaterial();

    void setStreetName(QString name);
    void setNumber(QString number);
    void setLevels(int levels);
    void setType(QString type);
    void setType(int type);
    void setMaterial(int index);
    void setMaterial(QString material);

private:
    QString street_;
    QString number_;
    int levels_;
    Materials material_;
    //public => public_building
    enum Types{yes, apartments, farm, hotel, house, detached, residential, dormitory, terrace, houseboat, bungalow, static_caravan, commercial,
               industrial, retail, warehouse, kiosk, cabin, religious, cathedral, chapel, church, mosque, temple, synagogue, shrine, bakehouse,
               kindergarten, civic, hospital, school, stadium, train_station, transportation, university, grandstand, public_building, barn,
               bridge, bunker, carport, conservatory, construction, cowshed, digester, farm_auxiliary, garage, garages, garbage_shed, greenhouse,
               hangar, hut, pavilion, parking, riding_hall, roof, shed, stable, sty, transformer_tower, service, ruins, water_tower};
    Types type_;
    const QList<QString> types_to_numbers_ = * new QList<QString>
            << "yes" << "apartments" << "farm" << "hotel" << "house" << "detached" << "residential" << "dormitory" << "terrace" << "houseboat" << "bungalow" << "static_caravan" << "commercial" <<
               "industrial" << "retail" << "warehouse" << "kiosk" << "cabin" << "religious" << "cathedral" << "chapel" << "church" << "mosque" << "temple" << "synagogue" << "shrine" << "bakehouse" <<
               "kindergarten" << "civic" << "hospital" << "school" << "stadium" << "train_station" << "transportation" << "university" << "grandstand" << "public" << "barn" <<
               "bridge" << "bunker" << "carport" << "conservatory" << "construction" << "cowshed" << "digester" << "farm_auxiliary" << "garage" << "garages" << "garbage_shed" << "greenhouse" <<
               "hangar" << "hut" << "pavilion" << "parking" << "riding_hall" << "roof" << "shed" << "stable" << "sty" << "transformer_tower" << "service" << "ruins" << "water_tower";
};

#endif // BUILDING_H
