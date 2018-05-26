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
    const int landuseCount = 33;

    bool readSettingsFromFile();

    QString getOpenFileDefPath();
    void setOpenFileDefPath(QString path);

    QColor getBuindingTypeColor(int type);
    QString getBuildingTypeAsString(int type);
    bool setBuildingTypeColor(int index, QColor color);

    QColor getLanduseColor(int index);
    QString getLanduseAsString(int index);
    bool setLanduseColor(int index, QColor color);

private:
    bool saveSettings();
    QVariantMap jsonSettings_;
    QVariantMap buildingColorSettings_;
    QVariantMap landuseColorSettings_;
    QFile file_;
    bool settingsLoaded_;
    QString openFileDefinePath_;

};

#endif // SETTINGS_H
