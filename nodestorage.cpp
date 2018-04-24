#include "nodestorage.h"

NodeStorage::NodeStorage()
{
    nodes_ = * new QList<QPointF>;
}
void NodeStorage::setBounds(double minlat, double minlon, double maxlat, double maxlon){
    corrLat_ = maxlat - minlat;
    corrLon_ = maxlon - minlon;
    return;
}
void NodeStorage::addNode(QString id, double lat, double lon){
    nodes_.push_back(* new QPointF(lat, lon));
    association_.insert(id, nodes_.length() - 1);
    qDebug() << "Node added. Array id:" << nodes_.length() - 1 << "Xml id:" << id;
    return;
}
