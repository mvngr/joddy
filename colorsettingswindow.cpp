#include "colorsettingswindow.h"
#include "ui_colorsettingswindow.h"

ColorSettingsWindow::ColorSettingsWindow(JoddyController *controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ColorSettingsWindow)
{
    ui->setupUi(this);

    jc_ = controller;

    colorsList_ = ui->list;
    ui->defOpenFilePathLine->setText(jc_->getSettings()->getOpenFileDefPath());

    //TODO MOVE IN FUNCTION!!




}

ColorSettingsWindow::~ColorSettingsWindow()
{
    delete ui;
}

void ColorSettingsWindow::onColorClicked()
{
    QToolButton* btn = qobject_cast<QToolButton*>(sender()); //get sender button
    QColor currentColor = QColorDialog::getColor(jc_->getSettings()->getBuindingTypeColor(btn->objectName().toInt()));
    if(currentColor.isValid()){
        jc_->getSettings()->setBuildingTypeColor(btn->objectName().toInt(), currentColor);
        QPixmap p(COLOR_VIEW_SIZE, COLOR_VIEW_SIZE);
        p.fill(currentColor);
        btn->setIcon(p);
    }
    return;
}
void ColorSettingsWindow::onLanduseClicked(){
    QToolButton* btn = qobject_cast<QToolButton*>(sender()); //get sender button
    QColor currentColor = QColorDialog::getColor(jc_->getSettings()->getLanduseColor(btn->objectName().toInt()));
    if(currentColor.isValid()){
        jc_->getSettings()->setLanduseColor(btn->objectName().toInt(), currentColor);
        QPixmap p(COLOR_VIEW_SIZE, COLOR_VIEW_SIZE);
        p.fill(currentColor);
        btn->setIcon(p);
    }
    return;
}

void ColorSettingsWindow::on_defOpenFilePathBtn_clicked()
{
    QString path = QFileDialog::getExistingDirectory(0, "Выбор стандартной папки для открытия файлов", jc_->getSettings()->getOpenFileDefPath());
    ui->defOpenFilePathLine->setText(path);
    jc_->getSettings()->setOpenFileDefPath(ui->defOpenFilePathLine->text());
}

void ColorSettingsWindow::showColorsList(ObjectName objectName){
    QLayoutItem * item, * subitem;
    auto list = colorsList_->children();
    for(int i = 0; i < list.size(); i++){
        auto sublist = list[i]->children();
        for(int j = 0; j < sublist.size(); j++){
            qDebug() << sublist[i];
        }
    }
//    while(!colorsList_->isEmpty()){
//        //    for(int i = 0; i < colorsList_->layout()->count(); i++){
//        item = colorsList_->takeAt(0);
//        while(!item->layout()->isEmpty()){
//            //        for(int i = 0; i < item->layout()->count(); i++){
//            subitem = item->layout()->takeAt(0);
//            item->layout()->removeItem(subitem);
//            item->layout()->removeWidget(subitem->widget());
//            delete subitem->widget();
//            delete subitem;
//            item->layout()->update();
//        }
//        colorsList_->removeItem(item);
//        colorsList_->removeWidget(item->widget());
//        delete item->widget();
//        delete item;
//        colorsList_->update();
//    }

    switch (objectName) {
    case ObjectName::Building: showBuildingColorList(); break;
    case ObjectName::Landuse: showLanduseColorList(); break;
    default: throw "Show colors list error. Object name not found."; break;
    }
    return;
}

void ColorSettingsWindow::showBuildingColorList(){
    for(int i = 0; i < jc_->getSettings()->typesCount; i++){
        QHBoxLayout *rowLayout = new QHBoxLayout(this);
        QPixmap pm(COLOR_VIEW_SIZE, COLOR_VIEW_SIZE);
        pm.fill(jc_->getSettings()->getBuindingTypeColor(i));
        QToolButton *btn = new QToolButton(this);
        btn->setObjectName(QString::number(i));
        btn->setIcon(pm);
        btn->setFixedSize(COLOR_BUTTON_SIZE, COLOR_BUTTON_SIZE);
        connect(btn, SIGNAL(clicked()), this, SLOT(onColorClicked()));

        QLabel *name = new QLabel(this);
        name->setText(jc_->getSettings()->getBuildingTypeAsString(i));

        rowLayout->addWidget(btn);
        rowLayout->addWidget(name);

        colorsList_->addLayout(rowLayout);
    }
    return;
}

void ColorSettingsWindow::showLanduseColorList(){
    for(int i = 0; i < jc_->getSettings()->landuseCount; i++){
        QHBoxLayout *rowLayout = new QHBoxLayout(this);
        QPixmap pm(COLOR_VIEW_SIZE, COLOR_VIEW_SIZE);
        pm.fill(jc_->getSettings()->getLanduseColor(i));
        QToolButton *btn = new QToolButton(this);
        btn->setObjectName(QString::number(i));
        btn->setIcon(pm);
        btn->setFixedSize(COLOR_BUTTON_SIZE, COLOR_BUTTON_SIZE);
        connect(btn, SIGNAL(clicked()), this, SLOT(onLanduseClicked()));

        QLabel *name = new QLabel(this);
        name->setText(jc_->getSettings()->getLanduseAsString(i));

        rowLayout->addWidget(btn);
        rowLayout->addWidget(name);

        colorsList_->addLayout(rowLayout);
    }
}

void ColorSettingsWindow::on_comboBox_activated(int index)
{
    showColorsList(ObjectName(index));
    return;
}
