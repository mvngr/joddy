#ifndef JODDYGRAPHICVIEW_H
#define JODDYGRAPHICVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QTimer>
#include <QDebug>
#include <building.h>
#include <way.h>
#include <QtSvg/QGraphicsSvgItem>
#include <QDir>

class JoddyGraphicView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit JoddyGraphicView(QWidget *parent = 0);
    ~JoddyGraphicView();
    void setPoints(QList<QPointF> *list);
    void setBuildings(QList<Building *> *list);
    void setWays(QList<Way *> *list);
    void printDots();

signals:

private slots:
    void slotAlarmTimer();

private:
    QGraphicsScene *scene;
    QGraphicsItemGroup *group_1;
    QGraphicsItemGroup *group_2;

    QGraphicsItemGroup *gPoints_;
    QGraphicsItemGroup *placeholder_;

    QGraphicsSvgItem *svgPlaceholder_;

private:
    QTimer *mapUpdate_;
    QList<QPointF> *points_;
    QList<Building *> *buildings_;
    QList<Way *> *ways_;
    bool temp;
    void resizeEvent(QResizeEvent *event);
    void deleteItemsFromGroup(QGraphicsItemGroup *group_1);
};

#endif // JODDYGRAPHICVIEW_H
