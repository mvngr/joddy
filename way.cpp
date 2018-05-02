#include "way.h"

Way::Way(){}
Way::Way(QList<QPointF> points):Object(points, Object::stone){}

QPolygonF Way::getPolygon(){
    return poly_;
}
void Way::setPolygon(QPolygonF polygon){
    poly_ = polygon;
    return;
}
QList<QPointF> Way::getPoints(){
    return Object::getPoints();
}
