#include "joddycontroller.h"

JoddyController::JoddyController()
{
    nodeStorage_ = new NodeStorage();
    buildings_ = new QList<Building *>;

}
NodeStorage * JoddyController::getNodeStorage(){
    return nodeStorage_;
}
void JoddyController::setMap(JoddyGraphicView *map){
    map_ = map;
    map_->setPoints(nodeStorage_->getNodes());
    map_->setBuildings(buildings_);
    return;
}
void JoddyController::setBuilding(Building * b){
    buildings_->push_back(b);
    buildings_->last()->setPolygon(QPolygonF(buildings_->last()->getPoints().toVector())); //TODO buildings have 0 point size
    return;
}
