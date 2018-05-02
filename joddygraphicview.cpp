#include "joddygraphicview.h"

JoddyGraphicView::JoddyGraphicView(QWidget *parent) : QGraphicsView(parent){
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setAlignment(Qt::AlignCenter);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setRenderHint(QPainter::Antialiasing);

    this->setMinimumHeight(100);
    this->setMinimumWidth(100);

    scene = new QGraphicsScene();
    this->setScene(scene);

    group_1 = new QGraphicsItemGroup();
    group_2 = new QGraphicsItemGroup();

    gPoints_ = new QGraphicsItemGroup();
    placeholder_ = new QGraphicsItemGroup();

    svgPlaceholder_ = new QGraphicsSvgItem("source/logo.svg");
    svgPlaceholder_->setTransform(QTransform(0.5, 0, 0, 0.5, 0, 0));
    placeholder_->addToGroup(svgPlaceholder_);

    scene->addItem(group_1);
    scene->addItem(group_2);
    scene->addItem(gPoints_);
    scene->addItem(placeholder_);

    temp = false;

    mapUpdate_ = new QTimer();
    connect(mapUpdate_, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));
    mapUpdate_->start(50);
}
JoddyGraphicView::~JoddyGraphicView(){}
void JoddyGraphicView::slotAlarmTimer(){
    this->deleteItemsFromGroup(group_1);
    this->deleteItemsFromGroup(group_2);
    if(points_->size() != 0)
        this->deleteItemsFromGroup(placeholder_);

    int width = this->width();
    int height = this->height();

    scene->setSceneRect(0,0,width,height);

    QPen penBlack(Qt::black);
    QPen penBuild(Qt::black);
    QPen penWay(Qt::darkGray);



    if(!temp && points_->size() != 0){
        for(int i = 0; i < buildings_->length(); i++){
            auto p = buildings_->at(i)->getPolygon();
            gPoints_->addToGroup(scene->addPolygon(p, penBuild, QBrush(QColor(205,245,248))));
        }
        for(int i = 0; i < ways_->length(); i++){
            gPoints_->addToGroup(scene->addPolygon(ways_->at(i)->getPolygon(), penWay, QBrush(QColor(0,0,0,0))));
        }
//        for(int i = 0; i < points_->size(); i++) {
//            QPointF f = points_->at(i);
//            gPoints_->addToGroup(scene->addEllipse(f.rx(), f.ry(), 1, 1, penBlack, QBrush(Qt::SolidPattern)));
//        }
//        gPoints_->setScale(0.1);
//        gPoints_->transform().translate(500,600);

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
