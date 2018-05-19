#include "settings.h"

Settings::Settings()
{
    settings_loaded_ = false;
    readSettingsFromFile();
}
bool Settings::readSettingsFromFile(){
    QFile file_obj((QString)DEFAULT_NAME_OF_SETTINGS + (QString)".json");
    if (!file_obj.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open " << DEFAULT_NAME_OF_SETTINGS << ".json";
        return false;
    }

    QTextStream file_text(&file_obj);
    QString json_string = file_text.readAll();
    file_obj.close();
    QByteArray json_bytes = json_string.toLocal8Bit();

    QJsonDocument json_doc = QJsonDocument::fromJson(json_bytes);
    if (json_doc.isNull()){
        qDebug() << "Failed to create JSON doc.";
        return false;
    }
    if (!json_doc.isObject()){
        qDebug() << "JSON is not an object.";
        return false;
    }

    QJsonObject json_obj = json_doc.object();
    if(json_obj.isEmpty()){
        qDebug()<<"JSON object is empty.";
        return false;
    }

    json_settings_ = json_obj.toVariantMap();
    color_settings_ = json_settings_["type_colors"].toMap();
    settings_loaded_ = true;
    return true;
}
QColor Settings::getColor(int type){
    if(!settings_loaded_){
        throw "The settings file is not found";
        return QColor(255,0,0);
    }
    QVariantMap rgb = color_settings_[getTypeAsString((int)type)].toMap();
    return QColor(rgb["r"].toInt(), rgb["g"].toInt(), rgb["b"].toInt());
}
QString Settings::getTypeAsString(int type){
    switch (type) {
    case 0 : return "yes"; break;
    case 1 : return "apartments"; break;
    case 2 : return "farm"; break;
    case 3 : return "hotel"; break;
    case 4 : return "house"; break;
    case 5 : return "detached"; break;
    case 6 : return "residential"; break;
    case 7 : return "dormitory"; break;
    case 8 : return "terrace"; break;
    case 9 : return "houseboat"; break;
    case 10 : return "bungalow"; break;
    case 11 : return "static_caravan"; break;
    case 12 : return "commercial"; break;
    case 13 : return "industrial"; break;
    case 14 : return "retail"; break;
    case 15 : return "warehouse"; break;
    case 16 : return "kiosk"; break;
    case 17 : return "cabin"; break;
    case 18 : return "religious"; break;
    case 19 : return "cathedral"; break;
    case 20 : return "chapel"; break;
    case 21 : return "church"; break;
    case 22 : return "mosque"; break;
    case 23 : return "temple"; break;
    case 24 : return "synagogue"; break;
    case 25 : return "shrine"; break;
    case 26 : return "bakehouse"; break;
    case 27 : return "kindergarten"; break;
    case 28 : return "civic"; break;
    case 29 : return "hospital"; break;
    case 30 : return "school"; break;
    case 31 : return "stadium"; break;
    case 32 : return "train_station"; break;
    case 33 : return "transportation"; break;
    case 34 : return "university"; break;
    case 35 : return "grandstand"; break;
    case 36 : return "public"; break;
    case 37 : return "barn"; break;
    case 38 : return "bridge"; break;
    case 39 : return "bunker"; break;
    case 40 : return "carport"; break;
    case 41 : return "conservatory"; break;
    case 42 : return "construction"; break;
    case 43 : return "cowshed"; break;
    case 44 : return "digester"; break;
    case 45 : return "farm_auxiliary"; break;
    case 46 : return "garage"; break;
    case 47 : return "garages"; break;
    case 48 : return "garbage_shed"; break;
    case 49 : return "greenhouse"; break;
    case 50 : return "hangar"; break;
    case 51 : return "hut"; break;
    case 52 : return "pavilion"; break;
    case 53 : return "parking"; break;
    case 54 : return "riding_hall"; break;
    case 55 : return "roof"; break;
    case 56 : return "shed"; break;
    case 57 : return "stable"; break;
    case 58 : return "sty"; break;
    case 59 : return "transformer_tower"; break;
    case 60 : return "service"; break;
    case 61 : return "ruins"; break;
    case 62 : return "water_tower"; break;
    case 63 : return "collapsed"; break;
    default: return "ERROR"; break;
    }
}
bool Settings::setColor(int index, QColor color){
    QVariantMap m;
    m["r"] = color.red();
    m["g"] = color.green();
    m["b"] = color.blue();
    color_settings_[getTypeAsString(index)].setValue(m);
    saveSettings();
    return true;
}
bool Settings::saveSettings(){
    QFile file_obj((QString)DEFAULT_NAME_OF_SETTINGS + (QString)".json");
    if (!file_obj.open(QIODevice::WriteOnly)) {
        qDebug() << "Failed to open " << DEFAULT_NAME_OF_SETTINGS << ".json";
        return false;
    }
    if(json_settings_.isEmpty())
        return false;
    QJsonObject obj;
    json_settings_["type_colors"].setValue(color_settings_);
    QJsonDocument * d = new QJsonDocument( obj.fromVariantMap(json_settings_) );

    file_obj.write(d->toJson());
    file_obj.close();
    return true;
}
void Settings::setOpenFileDefPath(QString path){
    if(path.size() != 0){
        json_settings_["def_path"].setValue(path);
        saveSettings();
    }
    return;
}
QString Settings::getOpenFileDefPath(){
    return json_settings_["def_path"].toString();
}
