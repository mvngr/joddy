#include "joddycontroller.h"

JoddyController::JoddyController()
{
    nodeStorage_ = new NodeStorage();
}
NodeStorage * JoddyController::getNodeStorage(){
    return nodeStorage_;
}
void JoddyController::connectTimer(){
    mapUpdate_ = new QTimer();
    //connect(mapUpdate_, SIGNAL(timeout()), this, SLOT(map_->slotAlarmTimer()));
    mapUpdate_->start(50);
}
