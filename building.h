#ifndef BUILDING_H
#define BUILDING_H

#include <object.h>
#include <QDebug>
#include <QString>

class Building : Object
{
public:
    Building();
private:
    QString street_;
    QString number_;
    int levels_;
    Materials material_;


};

#endif // BUILDING_H
