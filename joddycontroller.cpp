#include "joddycontroller.h"

JoddyController::JoddyController()
{
    nodeStorage_ = new NodeStorage();
}
NodeStorage * JoddyController::getNodeStorage(){
    return nodeStorage_;
}
