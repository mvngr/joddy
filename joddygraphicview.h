#ifndef JODDYGRAPHICVIEW_H
#define JODDYGRAPHICVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QTimer>
#include <QDebug>
#include <building.h>

class JoddyGraphicView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit JoddyGraphicView(QWidget *parent = 0);
    ~JoddyGraphicView();
    void setPoints(QList<QPointF> * list);
    void setBuildings(QList<Building * > * list);

signals:

private slots:
    void slotAlarmTimer();

private:
    QGraphicsScene *scene;
    QGraphicsItemGroup *group_1;
    QGraphicsItemGroup *group_2;
    QGraphicsItemGroup *gPoints_;

private:
    QTimer * mapUpdate_;
    QList<QPointF> * points_;
    QList<Building * > * buildings_;
    bool temp;
    void resizeEvent(QResizeEvent *event);
    void deleteItemsFromGroup(QGraphicsItemGroup *group_1);
};

#endif // JODDYGRAPHICVIEW_H
