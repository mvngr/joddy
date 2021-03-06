#ifndef JODDYGRAPHICVIEW_H
#define JODDYGRAPHICVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QTimer>
#include <QDebug>
#include <QtSvg/QGraphicsSvgItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneMoveEvent>

#include <building.h>
#include <way.h>
#include <settings.h>
#include <nature.h>

#define DELTA_STROKE_AND_FILL_COLOR 40

#define ZOOM_DEF 1.0
#define ZOOM_DELTA 0.1

class JoddyGraphicView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit JoddyGraphicView(Settings *settings, QWidget *parent = 0);
    ~JoddyGraphicView();

    const double ZOOM_MAX = 2.5;
    const double ZOOM_MIN = 0.3;

    void setPoints(QList<QPointF> *list);
    void setBuildings(QList<Building *> *list);
    void setWays(QList<Way *> *list);
    void setNature(QList<Nature *> *list);

    void printDots();
    void zoomIn();
    void zoomOut();
    double getZoom();

signals:

private slots:
    void drawNewFrame();

private:
    double zoom_;

    QGraphicsScene *scene;

    QGraphicsItemGroup *gPoints_;
    QGraphicsItemGroup *placeholder_;

    QGraphicsSvgItem *svgPlaceholder_;

    Settings * settings_;
    QTimer *mapUpdate_;
    QList<QPointF> *points_;
    QList<Building *> *buildings_;
    QList<Way *> *ways_;
    QList<Nature *> *nature_;
    bool temp;
    double dx_,dy_;
    void resizeEvent(QResizeEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void deleteItemsFromGroup(QGraphicsItemGroup *group_1);

    QColor typeToStrokeColor(Building::Types type);
    QColor landuseToStrokeColor(Nature::Landuse landuse);

    QColor strokeToFillColor(QColor strokeColor);
    QColor makeLighter(QColor color);
};

#endif // JODDYGRAPHICVIEW_H
