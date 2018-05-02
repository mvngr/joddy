#ifndef JODDYCONTROLLER_H
#define JODDYCONTROLLER_H
#include <nodestorage.h>
#include <joddygraphicview.h>
#include <building.h>
#include <way.h>

class JoddyController
{
public:
    JoddyController();
    NodeStorage *getNodeStorage();

    void setMap(JoddyGraphicView *map);
    void setBuilding(Building *b);
    void setWay(Way *w);

private:
    NodeStorage *nodeStorage_;
    JoddyGraphicView *map_;
    QList<Building *> *buildings_;
    QList<Way *> *ways_;

};

#endif // JODDYCONTROLLER_H
