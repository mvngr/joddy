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
        parser_ = new OsmParser(fileName, controller_);
        parser_->readFile();
    }
}
