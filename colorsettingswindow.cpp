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

    for(int i = 0; i < jc_->getSettings()->typesCount; i++){
        QHBoxLayout *rowLayout = new QHBoxLayout(this);
        QPixmap pm(COLOR_VIEW_SIZE, COLOR_VIEW_SIZE);
        pm.fill(jc_->getSettings()->getColor(i));
        QToolButton *btn = new QToolButton(this);
        btn->setObjectName(QString::number(i));
        btn->setIcon(pm);
        btn->setFixedSize(COLOR_BUTTON_SIZE, COLOR_BUTTON_SIZE);
        connect(btn, SIGNAL(clicked()), this, SLOT(onColorClicked()));

        QLabel *name = new QLabel(this);
        name->setText(jc_->getSettings()->getTypeAsString(i));

        rowLayout->addWidget(btn);
        rowLayout->addWidget(name);

        colorsList_->addLayout(rowLayout);
    }
}

ColorSettingsWindow::~ColorSettingsWindow()
{
    delete ui;
}

void ColorSettingsWindow::onColorClicked()
{
    QToolButton* btn = qobject_cast<QToolButton*>(sender()); //get sender button
    QColor currentColor = QColorDialog::getColor(jc_->getSettings()->getColor(btn->objectName().toInt()));
    if(currentColor.isValid()){
        jc_->getSettings()->setColor(btn->objectName().toInt(), currentColor);
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
