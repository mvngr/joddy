#include "object.h"

Object::Object()
{
    setPoints(* new QList<QPointF>);
    setStrokeColor(Qt::red);
    setFillColor(QColor(255,0,0,128));
}
Object::Object(QList<QPointF> points){
    setPoints(points);
    setStrokeColor(Qt::black);
    setFillColor(QColor(0,0,0,32));
}
Object::Object(QList<QPointF> points, QColor stroke, QColor fill){
    setPoints(points);
    setStrokeColor(stroke);
    setFillColor(fill);
}
void Object::setPoints(QList<QPointF> points){
    points_ = points;
    return;
}
void Object::addPoint(double x, double y){
    points_.push_back(QPointF(x,y));
    return;
}
void Object::addPoint(QPointF point){
    points_.push_back(point);
    return;
}
void Object::setStrokeColor(QColor color){
    stroke_ = color;
}
void Object::setFillColor(QColor color){
    fill_ = color;
}
QList<QPointF> Object::getPoints(){
    return points_;
}
QColor Object::getStrokeColor(){
    return stroke_;
}
QColor Object::getFillColor(){
    return fill_;
}
QString Object::getMaterial(){
    return materials_to_numbers_[material_];
}
QPointF Object::getPoint(int index){
    return index >= 0 && index < points_.size() ? points_[index] : QPointF();
}
void Object::setMaterial(QString material){
    int number_type = materials_to_numbers_.indexOf(material);
    material_ = static_cast<Materials>(number_type != -1 ? number_type : 0);
    return;
}
void Object::setMaterial(int index){
    material_ = static_cast<Materials>(index >= 0 && index < materials_to_numbers_.size() ? index : 0);
    return;
}
