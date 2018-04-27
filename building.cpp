#include "building.h"

Building::Building():Object(){}
Building::Building(QList<QPointF> points):Object(points){}
Building::Building(QList<QPointF> points, QColor stroke, QColor fill):Object(points, stroke, fill){}
QString Building::getStreetName(){
    return street_;
}
QString Building::getNumber(){
    return number_;
}
int Building::getLevels(){
    return levels_;
}
QString Building::getType(){
    return types_to_numbers_[type_];
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
