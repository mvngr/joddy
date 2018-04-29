#ifndef JODDYCONTROLLER_H
#define JODDYCONTROLLER_H
#include <nodestorage.h>
#include <joddygraphicview.h>
#include <building.h>

class JoddyController
{
public:
    JoddyController();
    NodeStorage *getNodeStorage();
    void setMap(JoddyGraphicView *map);
    void setBuilding(Building *b);
private:
    NodeStorage *nodeStorage_;
    JoddyGraphicView *map_;
    QList<Building *> * buildings_;

};

#endif // JODDYCONTROLLER_H
