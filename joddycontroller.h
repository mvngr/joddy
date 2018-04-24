#ifndef JODDYCONTROLLER_H
#define JODDYCONTROLLER_H
#include <nodestorage.h>
#include <joddygraphicview.h>

class JoddyController
{
public:
    JoddyController();
    NodeStorage *getNodeStorage();
private:
    NodeStorage * nodeStorage_;
    JoddyGraphicView *map_;
};

#endif // JODDYCONTROLLER_H
