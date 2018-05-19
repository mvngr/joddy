#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    jc_ = new JoddyController();
    map_ = new JoddyGraphicView(jc_->getSettings());
    jc_->setMap(map_);
    progress_ = new QLabel(this);

    progress_->setText("Status: done");

    ui->statusBar->addWidget(progress_);
    ui->graphicLayout->addWidget(map_);

    zoomInBtn_ = new QToolButton(this);
    zoomOutBtn_ = new QToolButton(this);

    QToolButton * openMap1 = new QToolButton(this);
    QToolButton * openMap2 = new QToolButton(this);
    QToolButton * openMap3 = new QToolButton(this);

    zoomInBtn_->setIcon(QIcon("source/zoom-in-button.svg"));
    zoomOutBtn_->setIcon(QIcon("source/zoom-out-button.svg"));

    openMap1->setIcon(QIcon("source/logo-pic.svg"));
    openMap2->setIcon(QIcon("source/logo-pic.svg"));
    openMap3->setIcon(QIcon("source/logo-pic.svg"));

    ui->toolBar->addWidget(zoomInBtn_);
    ui->toolBar->addWidget(zoomOutBtn_);

    ui->toolBar->addWidget(openMap1);
    ui->toolBar->addWidget(openMap2);
    ui->toolBar->addWidget(openMap3);

    connect(zoomInBtn_, SIGNAL(clicked(bool)), this, SLOT(zoom_in_triggered()));
    connect(zoomOutBtn_, SIGNAL(clicked(bool)), this, SLOT(zoom_out_triggered()));

    connect(openMap1, SIGNAL(clicked(bool)), this, SLOT(on_openMap1_triggered()));
    connect(openMap2, SIGNAL(clicked(bool)), this, SLOT(on_openMap2_triggered()));
    connect(openMap3, SIGNAL(clicked(bool)), this, SLOT(on_openMap3_triggered()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openFile_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открыть файл"), jc_->getSettings()->getOpenFileDefPath(), tr("OpenStreetMap Files (*.osm)"));

    if (fileName != "") {
        QTime t;
        t.start();
        parser_ = new OsmParser(fileName, jc_);
        parser_->readFile();
        qDebug("Time elapsed: %d ms", t.elapsed());
    }
}
void MainWindow::on_openMap_triggered(QString path){

    QTime t;
    t.start();
    parser_ = new OsmParser(path, jc_);
    parser_->readFile();
    qDebug("Time elapsed: %d ms", t.elapsed());
}
void MainWindow::on_openSettings_triggered(){
    ColorSettingsWindow * v = new ColorSettingsWindow(jc_, this);
    v->setWindowFlags(v->windowFlags() & ~Qt::WindowContextHelpButtonHint); //remove "?" in window title
    v->show();
}
void MainWindow::zoom_in_triggered(){
    zoomOutBtn_->setEnabled(true);
    map_->zoomIn();
    if(map_->getZoom() >= map_->ZOOM_MAX)
        zoomInBtn_->setEnabled(false);
    else
        zoomInBtn_->setEnabled(true);
    return;
}
void MainWindow::zoom_out_triggered(){
    zoomInBtn_->setEnabled(true);
    map_->zoomOut();
    if(map_->getZoom() <= map_->ZOOM_MIN)
        zoomOutBtn_->setEnabled(false);
    else
        zoomOutBtn_->setEnabled(true);
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
