#ifndef SETTINGS_H
#define SETTINGS_H

#include <QColor>
#include <QMap>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QString>
#include <QByteArray>
#include <QJsonDocument>
#include <QVariant>

#include <building.h>
#include <object.h>

#define DEFAULT_NAME_OF_SETTINGS "settings"

class Settings
{
public:
    Settings();

    const int typesCount = 64;

    bool readSettingsFromFile();

    QColor getColor(int type);
    bool setColor(int index, QColor color);
    QString getTypeAsString(int type);
    void setOpenFileDefPath(QString path);
    QString getOpenFileDefPath();

private:
    bool saveSettings();
    QVariantMap json_settings_;
    QVariantMap color_settings_;
    QFile file_;
    bool settings_loaded_;
    QString openFileDefinePath_;

};

#endif // SETTINGS_H
