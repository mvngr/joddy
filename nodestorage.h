#ifndef NODESTORAGE_H
#define NODESTORAGE_H
#include <QString>
#include <QList>
#include <QMap>
#include <QPointF>
#include <QDebug>

class NodeStorage
{
public:
    NodeStorage();
    void setBounds(double minlat, double minlon, double maxlat, double maxlon);
    void addNode(QString id, double lat, double lon);

private:
    QList<QPointF> nodes_;
    QMap<QString, int> association_;

    double corrLat_;
    double corrLon_;

};

#endif // NODESTORAGE_H
