#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QString>
#include <QFileDialog>
#include <QLabel>
#include <joddygraphicview.h>
#include <joddycontroller.h>
#include <osmparser.h>
#include <building.h>

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

private:
    Ui::MainWindow *ui;
    JoddyGraphicView *map_;
    JoddyController *controller_;
    OsmParser *parser_;
    QLabel *progress_;
};

#endif // MAINWINDOW_H
