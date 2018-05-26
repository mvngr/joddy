#include "joddygraphicview.h"

JoddyGraphicView::JoddyGraphicView(Settings *settings, QWidget *parent) : QGraphicsView(parent){

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
    settings_ = settings;
    gPoints_ = new QGraphicsItemGroup();
    placeholder_ = new QGraphicsItemGroup();

    svgPlaceholder_ = new QGraphicsSvgItem("source/logo.svg");
    svgPlaceholder_->setTransform(QTransform(0.5, 0, 0, 0.5, 0, 0));
    placeholder_->addToGroup(svgPlaceholder_);

    scene->addItem(gPoints_);
    scene->addItem(placeholder_);

    temp = false;

    mapUpdate_ = new QTimer();
    connect(mapUpdate_, SIGNAL(timeout()), this, SLOT(drawNewFrame()));
    mapUpdate_->start(50);
}
JoddyGraphicView::~JoddyGraphicView(){}

void JoddyGraphicView::drawNewFrame(){
    if(points_->size() != 0)
        this->deleteItemsFromGroup(placeholder_);

    int width = this->width();
    int height = this->height();

    scene->setSceneRect(0,0,width,height);

    QPen penWay(Qt::darkGray);

    if(!temp && points_->size() != 0){
        this->deleteItemsFromGroup(gPoints_);

        for(int i = 0; i < nature_->length(); i++){
            QColor color = makeLighter(landuseToStrokeColor(nature_->at(i)->getLanduse()));
            gPoints_->addToGroup(scene->addPolygon(nature_->at(i)->getPolygon(), color, color));
        }

        for(int i = 0; i < buildings_->length(); i++){
            Building::Types type = buildings_->at(i)->getType();
            QColor color = typeToStrokeColor(type);
            gPoints_->addToGroup(scene->addPolygon(buildings_->at(i)->getPolygon(), color, strokeToFillColor(color)));
        }

        for(int i = 0; i < ways_->length(); i++){
            for(int j = 0; j < ways_->at(i)->getPathLine()->size(); j++)
                gPoints_->addToGroup(scene->addLine(ways_->at(i)->getPathLine()->at(j), penWay));
        }

        temp = true;
    }
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
    drawNewFrame();
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
    drawNewFrame();
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
void JoddyGraphicView::setNature(QList<Nature *> *list){
    nature_ = list;
    return;
}
void JoddyGraphicView::zoomIn(){
    zoom_ = (zoom_ <= ZOOM_MAX) ? (zoom_ + ZOOM_DELTA) : zoom_;
    gPoints_->setScale(zoom_);
    return;
}
void JoddyGraphicView::zoomOut(){
    zoom_ = (zoom_ > ZOOM_MIN) ? (zoom_ - ZOOM_DELTA) : zoom_;
    gPoints_->setScale(zoom_);
    return;
}
QColor JoddyGraphicView::typeToStrokeColor(Building::Types type){
    QColor c = settings_->getBuindingTypeColor((int)type);
    if(c.red() == 0 && c.green() == 0 && c.blue() == 0)
        return settings_->getBuindingTypeColor(0);
    return c;
}
QColor JoddyGraphicView::landuseToStrokeColor(Nature::Landuse landuse){
    QColor c = settings_->getLanduseColor((int)landuse);
    if(c.red() == 0 && c.green() == 0 && c.blue() == 0)
        return settings_->getLanduseColor(0);
    return c;
}
QColor JoddyGraphicView::strokeToFillColor(QColor strokeColor){
    return QColor(strokeColor.red() + DELTA_STROKE_AND_FILL_COLOR < 255 ? strokeColor.red() + DELTA_STROKE_AND_FILL_COLOR : strokeColor.red(),
                  strokeColor.green() + DELTA_STROKE_AND_FILL_COLOR < 255 ? strokeColor.green() + DELTA_STROKE_AND_FILL_COLOR : strokeColor.green(),
                  strokeColor.blue() + DELTA_STROKE_AND_FILL_COLOR < 255 ? strokeColor.blue() + DELTA_STROKE_AND_FILL_COLOR : strokeColor.blue());
}
double JoddyGraphicView::getZoom(){
    return zoom_;
}
QColor JoddyGraphicView::makeLighter(QColor color){
    color.setRed(color.red() + 10 > 255 ? 255 : color.red() + 10);
    color.setGreen(color.green() + 10 > 255 ? 255 : color.green() + 10);
    color.setBlue(color.blue() + 10 > 255 ? 255 : color.blue() + 10);
    return color;
}
