#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QString>
#include <QFileDialog>
#include <QLabel>
#include <QTime>
#include <QToolButton>
#include <joddygraphicview.h>
#include <joddycontroller.h>
#include <osmparser.h>
#include <building.h>
#include <settings.h>
#include <colorsettingswindow.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_openFile_triggered();
    void on_openSettings_triggered();
    void zoom_in_triggered();
    void zoom_out_triggered();
    void on_openMap1_triggered();
    void on_openMap2_triggered();
    void on_openMap3_triggered();

private:
    QToolButton * zoomInBtn_;
    QToolButton * zoomOutBtn_;
    double zoom_;
    void on_openMap_triggered(QString path);
    Ui::MainWindow *ui;
    JoddyGraphicView *map_;
    JoddyController *jc_;
    OsmParser *parser_;
    QLabel *progress_;
};

#endif // MAINWINDOW_H
