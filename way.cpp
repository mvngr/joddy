#include "way.h"

Way::Way(){
    poly_ = * new QList<QLineF>;
}
Way::Way(QList<QPointF> points):Object(points, Object::stone){
    poly_ = * new QList<QLineF>;
}

QList<QLineF> *Way::getPathLine(){
    return &poly_;
}
void Way::setPathLine(QList<QPointF> polygon){
    for(int i = 0; i < polygon.length() - 1; i++)
        poly_.push_back(QLineF(polygon[i], polygon[i+1]));
    return;
}
QList<QPointF> Way::getPoints(){
    return Object::getPoints();
}
