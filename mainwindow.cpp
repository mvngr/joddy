#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    controller_ = new JoddyController();
    map_ = new JoddyGraphicView();
    controller_->setMap(map_);
    progress_ = new QLabel(this);

    progress_->setText("Status: done");

    ui->statusBar->addWidget(progress_);
    ui->graphicLayout->addWidget(map_);

    QToolButton * zoomIn = new QToolButton(this);
    QToolButton * zoomOut = new QToolButton(this);

    QToolButton * openMap1 = new QToolButton(this);
    QToolButton * openMap2 = new QToolButton(this);
    QToolButton * openMap3 = new QToolButton(this);

    zoomIn->setIcon(QIcon("source/zoom-in-button.svg"));
    zoomOut->setIcon(QIcon("source/zoom-out-button.svg"));

    openMap1->setIcon(QIcon("source/logo-pic.svg"));
    openMap2->setIcon(QIcon("source/logo-pic.svg"));
    openMap3->setIcon(QIcon("source/logo-pic.svg"));

    ui->toolBar->addWidget(zoomIn);
    ui->toolBar->addWidget(zoomOut);

    ui->toolBar->addWidget(openMap1);
    ui->toolBar->addWidget(openMap2);
    ui->toolBar->addWidget(openMap3);

    connect(zoomIn, SIGNAL(clicked(bool)), this, SLOT(zoom_in_triggered()));
    connect(zoomOut, SIGNAL(clicked(bool)), this, SLOT(zoom_out_triggered()));

    connect(openMap1, SIGNAL(clicked(bool)), this, SLOT(on_openMap1_triggered()));
    connect(openMap2, SIGNAL(clicked(bool)), this, SLOT(on_openMap2_triggered()));
    connect(openMap3, SIGNAL(clicked(bool)), this, SLOT(on_openMap3_triggered()));

    Settings * s = new Settings();
    s->readSettingsFromFile();
    qDebug() << s->getColor(Building::Types::yes);

    //Building b = * new Building();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openFile_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("OpenStreetMap Files (*.osm)"));

    if (fileName != "") {
        QTime t;
        t.start();
        parser_ = new OsmParser(fileName, controller_);
        parser_->readFile();
        qDebug("Time elapsed: %d ms", t.elapsed());
    }
}
void MainWindow::on_openMap_triggered(QString path){

    QTime t;
    t.start();
    parser_ = new OsmParser(path, controller_);
    parser_->readFile();
    qDebug("Time elapsed: %d ms", t.elapsed());
}
void MainWindow::zoom_in_triggered(){
    map_->zoomIn();
    return;
}
void MainWindow::zoom_out_triggered(){
    map_->zoomOut();
    return;
}
void MainWindow::on_openMap1_triggered(){
    on_openMap_triggered("C:/Users/Mike/Downloads/map (1).osm");
    return;
}
void MainWindow::on_openMap2_triggered(){
    on_openMap_triggered("C:/Users/Mike/Downloads/map (2).osm");
    return;
}
void MainWindow::on_openMap3_triggered(){
    on_openMap_triggered("C:/Users/Mike/Downloads/map (3).osm");
    return;
}
