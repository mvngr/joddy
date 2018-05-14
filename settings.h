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


    bool readSettingsFromFile();

    QColor getColor(Building::Types type);

private:
    QString getTypeAsString(Building::Types type);
    QVariantMap json_settings_;
    QFile file_;
    bool settings_loaded_;

};

#endif // SETTINGS_H
