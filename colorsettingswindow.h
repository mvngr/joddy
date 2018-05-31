#ifndef COLORSETTINGSWINDOW_H
#define COLORSETTINGSWINDOW_H

#include <QDialog>
#include <QLayout>
#include <QToolButton>
#include <QPixmap>
#include <QLabel>
#include <QColorDialog>
#include <QTextEdit>
#include <QTextDocumentFragment>
#include <QFileDialog>

#include <joddycontroller.h>

#define COLOR_BUTTON_SIZE 20
#define COLOR_VIEW_SIZE 64

namespace Ui {
class ColorSettingsWindow;
}

class ColorSettingsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ColorSettingsWindow(JoddyController * controller, QWidget *parent = 0);

    enum class ObjectName { Building, Landuse };
    void showColorsList(ObjectName objectName);

    ~ColorSettingsWindow();

private:
    QVBoxLayout * colorsList_;
    JoddyController * jc_;

    Ui::ColorSettingsWindow *ui;

    void showBuildingColorList();
    void showLanduseColorList();

private slots:
    void onColorClicked();
    void onLanduseClicked();
    void on_defOpenFilePathBtn_clicked();

    void on_comboBox_activated(int index);
};

#endif // COLORSETTINGSWINDOW_H
