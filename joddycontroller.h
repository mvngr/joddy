#ifndef JODDYCONTROLLER_H
#define JODDYCONTROLLER_H
#include <nodestorage.h>
#include <joddygraphicview.h>
#include <QTime>

class JoddyController
{
public:
    JoddyController();
    NodeStorage *getNodeStorage();
private:
    NodeStorage *nodeStorage_;
    JoddyGraphicView *map_;
    void connectTimer();
    QTimer *mapUpdate_;
};

#endif // JODDYCONTROLLER_H
