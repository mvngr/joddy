#include "osmparser.h"

OsmParser::OsmParser(QString path, JoddyController * controller){
    path_ = path;
    controller_ = controller;
    if(path != "")
        file_ = new QFile(path);
    else
        QMessageBox::critical(NULL, "Ошибка", "Файл " + path + " не найден");
}
bool OsmParser::readFile(){
    if (!file_->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(NULL, "Ошибка", "Невозможно открыть .osm файл");
        return false;
    }
    QXmlStreamReader xml(file_);

    QList<QString> temp_str_points_id = * new QList<QString>;

    //public => public_building
    QList<QString> types_to_numbers = * new QList<QString>
                << "yes" << "apartments" << "farm" << "hotel" << "house" << "detached" << "residential" << "dormitory" << "terrace" << "houseboat" << "bungalow" << "static_caravan" << "commercial" <<
                   "industrial" << "retail" << "warehouse" << "kiosk" << "cabin" << "religious" << "cathedral" << "chapel" << "church" << "mosque" << "temple" << "synagogue" << "shrine" << "bakehouse" <<
                   "kindergarten" << "civic" << "hospital" << "school" << "stadium" << "train_station" << "transportation" << "university" << "grandstand" << "public" << "barn" <<
                   "bridge" << "bunker" << "carport" << "conservatory" << "construction" << "cowshed" << "digester" << "farm_auxiliary" << "garage" << "garages" << "garbage_shed" << "greenhouse" <<
                   "hangar" << "hut" << "pavilion" << "parking" << "riding_hall" << "roof" << "shed" << "stable" << "sty" << "transformer_tower" << "service" << "ruins" << "water_tower";

    QList<QString> materials_to_numbers_ = * new QList<QString> << "wood" << "metal" << "brass" << "bronze" << "steel" << "concrete" << "reinforced_concrete"
                                                                          << "stone" << "granite" << "sandstone" << "masonry" << "brick" << "plastic" << "soil" << "glass";

    while (!xml.atEnd() && !xml.hasError())
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        if (token == QXmlStreamReader::StartDocument)
            continue;
        if (token == QXmlStreamReader::StartElement){
            if(xml.name() == "bounds" && xml.attributes().hasAttribute("minlat") && xml.attributes().hasAttribute("minlon")
                    && xml.attributes().hasAttribute("maxlat") && xml.attributes().hasAttribute("maxlon"))
                controller_->getNodeStorage()->setBounds(xml.attributes().value("minlat").toDouble(), xml.attributes().value("minlon").toDouble(),
                                                         xml.attributes().value("maxlat").toDouble(), xml.attributes().value("maxlon").toDouble());

            if(xml.name() == "node" && xml.attributes().hasAttribute("id") && xml.attributes().hasAttribute("lat") && xml.attributes().hasAttribute("lon"))
                controller_->getNodeStorage()->addNode(xml.attributes().value("id").toString(), xml.attributes().value("lon").toDouble(), xml.attributes().value("lat").toDouble());

            if(xml.name() == "way"){
                temp_str_points_id.clear();
            }

            if(xml.name() == "nd" && xml.attributes().hasAttribute("ref")){
                temp_str_points_id.push_back(xml.attributes().value("ref").toString());
            }

            if(xml.name() == "tag" && xml.attributes().hasAttribute("k") && xml.attributes().value("k") == "building" && xml.attributes().hasAttribute("v")){
                QList<QPointF> temp_points = * new QList<QPointF>;
                foreach (QString id, temp_str_points_id)
                    temp_points.push_back(controller_->getNodeStorage()->getPoint(id));
                int type = types_to_numbers.indexOf(xml.attributes().value("v").toString());
                controller_->setBuilding(new Building(temp_points, Building::Types(type), Object::Materials::metal));
                temp_str_points_id.clear();
            }

            if(xml.name() == "tag" && xml.attributes().hasAttribute("k") && xml.attributes().value("k") == "highway"){
                QList<QPointF> temp_points = * new QList<QPointF>;
                foreach (QString id, temp_str_points_id)
                    temp_points.push_back(controller_->getNodeStorage()->getPoint(id));
                controller_->setWay(new Way(temp_points));
                temp_str_points_id.clear();
            }
            //qDebug() << xml.name();
        }
    }
    controller_->getNodeStorage()->resizePlace();
    return true;
}
