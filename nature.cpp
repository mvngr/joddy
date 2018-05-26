#include "nature.h"

Nature::Nature()
{

}
Nature::Nature(QList<QPointF> points):Object(points, Object::Materials::brass){

}
Nature::Nature(QList<QPointF> points, Landuse landuse):Object(points, Object::Materials::brass){
    landuse_ = landuse;
}
void Nature::setPolygon(QPolygonF poly){
    poly_ = poly;
    return;
}
QPolygonF Nature::getPolygon(){
    return poly_;
}
QList<QPointF> Nature::getPoints(){
    return Object::getPoints();
}
Nature::Landuse Nature::getLanduse(){
    return landuse_;
}
void Nature::setLanduse(Landuse landuse){
    landuse_ = landuse;
}
