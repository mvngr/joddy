#ifndef NODESTORAGE_H
#define NODESTORAGE_H
#include <QString>
#include <QList>
#include <QMap>
#include <QPointF>
#include <QDebug>
#define PLACE_SIZE 1000

class NodeStorage
{
public:
    NodeStorage();
    void setBounds(double minlat, double minlon, double maxlat, double maxlon);
    void addNode(QString id, double lat, double lon);
    QList<QPointF> getNodes();
    void resizePlace();

private:
    QList<QPointF> nodes_;
    QMap<QString, int> association_;


    double minLat_;
    double minLon_;
    double corrLat_;
    double corrLon_;

    bool isResized_;

};

#endif // NODESTORAGE_H
