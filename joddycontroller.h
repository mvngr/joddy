#ifndef JODDYCONTROLLER_H
#define JODDYCONTROLLER_H
#include <nodestorage.h>
#include <joddygraphicview.h>
#include <building.h>
#include <way.h>
#include <settings.h>
#include <nature.h>

class JoddyController
{
public:
    JoddyController();
    NodeStorage *getNodeStorage();
    Settings *getSettings();

    void setMap(JoddyGraphicView *map);
    void setBuilding(Building *b);
    void setWay(Way *w);
    void setNature(Nature *n);

private:
    NodeStorage *nodeStorage_;
    JoddyGraphicView *map_;
    QList<Building *> *buildings_;
    QList<Way *> *ways_;
    QList<Nature *> *nature_;
    Settings *settings_;

};

#endif // JODDYCONTROLLER_H
