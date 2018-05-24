#include "nature.h"

Nature::Nature()
{

}
Nature::Nature(QList<QPointF> points):Object(points, Object::Materials::brass){

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
