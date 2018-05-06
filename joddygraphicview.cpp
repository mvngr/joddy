#include "joddygraphicview.h"

JoddyGraphicView::JoddyGraphicView(QWidget *parent) : QGraphicsView(parent){

    //area settings
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setAlignment(Qt::AlignCenter);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setRenderHint(QPainter::Antialiasing);
    this->setMinimumHeight(100);
    this->setMinimumWidth(100);
    scene = new QGraphicsScene();
    this->setScene(scene);


    //init values
    zoom_ = ZOOM_DEF;
    dx_ = 0;
    dy_ = 0;


    //init view items
    gPoints_ = new QGraphicsItemGroup();
    placeholder_ = new QGraphicsItemGroup();

    svgPlaceholder_ = new QGraphicsSvgItem("source/logo.svg");
    svgPlaceholder_->setTransform(QTransform(0.5, 0, 0, 0.5, 0, 0));
    placeholder_->addToGroup(svgPlaceholder_);

    scene->addItem(gPoints_);
    scene->addItem(placeholder_);

    temp = false;

    mapUpdate_ = new QTimer();
    connect(mapUpdate_, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));
    mapUpdate_->start(50);
}
JoddyGraphicView::~JoddyGraphicView(){}

void JoddyGraphicView::slotAlarmTimer(){
    if(points_->size() != 0)
        this->deleteItemsFromGroup(placeholder_);

    int width = this->width();
    int height = this->height();

    scene->setSceneRect(0,0,width,height);

    QPen penBlack(Qt::black);
    QPen penBuild(Qt::black);
    QPen penWay(Qt::darkGray);



    if(!temp && points_->size() != 0){
        this->deleteItemsFromGroup(gPoints_);
        for(int i = 0; i < buildings_->length(); i++){
            auto p = buildings_->at(i)->getPolygon();
            gPoints_->addToGroup(scene->addPolygon(p, penBuild, QBrush(QColor(205,245,248))));
        }
        for(int i = 0; i < ways_->length(); i++){
            for(int j = 0; j < ways_->at(i)->getPathLine()->size(); j++)
                gPoints_->addToGroup(scene->addLine(ways_->at(i)->getPathLine()->at(j), penWay));
        }
//        for(int i = 0; i < points_->size(); i++) {
//            QPointF f = points_->at(i);
//            gPoints_->addToGroup(scene->addEllipse(f.rx(), f.ry(), 1, 1, penBlack, QBrush(Qt::SolidPattern)));
//        }
        //gPoints_->setScale(zoom_);
        gPoints_->setTransform(QTransform(zoom_, 0, 0, zoom_, dx_, dy_));
        //gPoints_->transform().translate(dx_,dy_);

        temp = true;
    }

    /*
    QPen penBlack(Qt::black);
    QPen penRed(Qt::red);

    group_1->addToGroup(scene->addLine(20,20, width - 20, 20, penBlack));
    group_1->addToGroup(scene->addLine(width - 20, 20, width - 20, height -20, penBlack));
    group_1->addToGroup(scene->addLine(width - 20, height -20, 20, height -20, penBlack));
    group_1->addToGroup(scene->addLine(20, height -20, 20, 20, penBlack));

    int sideOfSquare = (height > width) ? (width - 60) : (height - 60);
    int centerOfWidget_X = width/2;
    int centerOfWidget_Y = height/2;

    group_2->addToGroup(scene->addLine(centerOfWidget_X - (sideOfSquare/2), centerOfWidget_Y - (sideOfSquare/2),
                                       centerOfWidget_X + (sideOfSquare/2), centerOfWidget_Y - (sideOfSquare/2), penRed));
    group_2->addToGroup(scene->addLine(centerOfWidget_X + (sideOfSquare/2), centerOfWidget_Y - (sideOfSquare/2),
                                       centerOfWidget_X + (sideOfSquare/2), centerOfWidget_Y + (sideOfSquare/2), penRed));
    group_2->addToGroup(scene->addLine(centerOfWidget_X + (sideOfSquare/2), centerOfWidget_Y + (sideOfSquare/2),
                                       centerOfWidget_X - (sideOfSquare/2), centerOfWidget_Y + (sideOfSquare/2), penRed));
    group_2->addToGroup(scene->addLine(centerOfWidget_X - (sideOfSquare/2), centerOfWidget_Y + (sideOfSquare/2),
                                       centerOfWidget_X - (sideOfSquare/2), centerOfWidget_Y - (sideOfSquare/2), penRed));
                                       */
    return;
}
void JoddyGraphicView::printDots(){
    this->deleteItemsFromGroup(gPoints_);

    QPen penBlack(Qt::black);

    for(int i = 0; i < points_->size(); i++) {
        QPointF f = points_->at(i);
        gPoints_->addToGroup(scene->addEllipse(f.rx(), f.ry(), 1, 1, penBlack, QBrush(Qt::SolidPattern)));
    }

}
void JoddyGraphicView::resizeEvent(QResizeEvent *event){
    QGraphicsView::resizeEvent(event);
    return;
}
void JoddyGraphicView::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF point = event->pos();
    temp = false;
    dx_ = point.x();
    dy_ = point.y();
    slotAlarmTimer();
}

void JoddyGraphicView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void JoddyGraphicView::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
void JoddyGraphicView::dragEnterEvent(QDragEnterEvent *event){
    QPoint point = event->pos();
    temp = false;
    dx_ = point.x();
    dy_ = point.y();
    slotAlarmTimer();
    return;
}
void JoddyGraphicView::deleteItemsFromGroup(QGraphicsItemGroup *group){
    foreach( QGraphicsItem *item, scene->items(group->boundingRect()))
        if(item->group() == group )
            delete item;
    return;
}
void JoddyGraphicView::setPoints(QList<QPointF> *list){
    points_ = list;
    return;
}
void JoddyGraphicView::setBuildings(QList<Building *> *list){
    buildings_ = list;
    return;
}
void JoddyGraphicView::setWays(QList<Way *> *list){
    ways_ = list;
    return;
}
void JoddyGraphicView::zoomIn(){
    zoom_ = (zoom_ < 2.4) ? (zoom_ + ZOOM_DELTA) : zoom_;
    temp = false;
    slotAlarmTimer();
    return;
}
void JoddyGraphicView::zoomOut(){
    zoom_ = (zoom_ > 0.3) ? (zoom_ - ZOOM_DELTA) : zoom_;
    temp = false;
    slotAlarmTimer();
    return;
}
