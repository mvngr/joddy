#include "joddycontroller.h"

JoddyController::JoddyController()
{
    nodeStorage_ = new NodeStorage();
    buildings_ = new QList<Building *>;
    ways_ = new QList<Way *>;

}
NodeStorage * JoddyController::getNodeStorage(){
    return nodeStorage_;
}
void JoddyController::setMap(JoddyGraphicView *map){
    map_ = map;
    map_->setPoints(nodeStorage_->getNodes());
    map_->setBuildings(buildings_);
    map_->setWays(ways_);
    return;
}
void JoddyController::setBuilding(Building * b){
    buildings_->push_back(b);
    buildings_->last()->setPolygon(QPolygonF(buildings_->last()->getPoints().toVector()));
    return;
}
void JoddyController::setWay(Way *w){
    ways_->push_back(w);
    ways_->last()->setPathLine(ways_->last()->getPoints());
    return;
}
