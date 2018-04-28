#ifndef JODDYGRAPHICVIEW_H
#define JODDYGRAPHICVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QTimer>
#include <QDebug>

class JoddyGraphicView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit JoddyGraphicView(QWidget *parent = 0);
    ~JoddyGraphicView();

signals:

private slots:
    void slotAlarmTimer();

private:
    QGraphicsScene *scene;
    QGraphicsItemGroup *group_1;
    QGraphicsItemGroup *group_2;
    QGraphicsItemGroup *points_;

private:
    void resizeEvent(QResizeEvent *event);
    void deleteItemsFromGroup(QGraphicsItemGroup *group_1);
};

#endif // JODDYGRAPHICVIEW_H
