#include "building.h"

Building::Building():Object(){}
Building::Building(QList<QPointF> points, Types type, Materials material):Object(points, material){
    type_ = type;
}
Building::Building(QList<QPointF> points, QColor stroke, QColor fill, Types type, Materials material):Object(points, stroke, fill, material){
    type_ = type;
}
QList<QPointF> Building::getPoints(){
    return Object::getPoints();
}
QString Building::getStreetName(){
    return street_;
}
QString Building::getNumber(){
    return number_;
}
int Building::getLevels(){
    return levels_;
}
void Building::setStreetName(QString name){
    street_ = name;
    return;
}
void Building::setNumber(QString number){
    number_ = number;
    return;
}
void Building::setLevels(int levels){
    levels_ = levels;
    return;
}
Building::Types Building::getType(){
    return type_;
}
/*
void Building::setType(int type){
    type_ = static_cast<Types>(type >= 0 && type < types_to_numbers_.size() ? type : 0);
    return;
}
void Building::setType(QString type){
    int number_type = types_to_numbers_.indexOf(type);
    type_ = static_cast<Types>(number_type != -1 ? number_type : 0);
    return;
}

void Building::setMaterial(int index){
    Object::setMaterial(index);
    return;
}
void Building::setMaterial(QString material){
    Object::setMaterial(material);
    return;
}
QString Building::getMaterial(){
    return Object::getMaterial();
}
*/
Building& Building::operator=(Building& other){
  street_ = other.street_;
  number_ = other.number_;
  levels_ = other.levels_;
  //material_ = other.material_;
  //type_ = other.type_;

  return *this;
}
QPolygonF Building::getPolygon(){
    return poly_;
}
void Building::setPolygon(QPolygonF poly){
    poly_ = poly;
    return;
}
