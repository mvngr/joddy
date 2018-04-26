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
