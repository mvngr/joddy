#include "nodestorage.h"

NodeStorage::NodeStorage()
{
    nodes_ = * new QList<QPointF>;
    isResized_ = false;
}
void NodeStorage::setBounds(double minlat, double minlon, double maxlat, double maxlon){
    corrLat_ = maxlat - minlat;
    corrLon_ = maxlon - minlon;
    minLat_ = minlat;
    minLon_ = minlon;
    return;
}
void NodeStorage::addNode(QString id, double lat, double lon){
    nodes_.push_back(* new QPointF(lat, lon));
    association_.insert(id, nodes_.length() - 1);
    qDebug() << "Node added. Array id:" << nodes_.length() - 1 << "Xml id:" << id;
    return;
}
QList<QPointF> NodeStorage::getNodes(){
    return nodes_;
}
void NodeStorage::resizePlace(){
    if(isResized_)
        return;
    double coefficient = (double)PLACE_SIZE / (corrLat_ > corrLon_ ? corrLat_ : corrLon_);

    for(int i = 0; i < nodes_.length(); i++)
        nodes_[i] = QPointF((nodes_[i].rx() - minLat_) * coefficient, (nodes_[i].ry() - minLon_) * coefficient);

    isResized_ = true;
    return;
}
