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
                controller_->getNodeStorage()->addNode(xml.attributes().value("id").toString(), xml.attributes().value("lat").toDouble(), xml.attributes().value("lon").toDouble());

            //qDebug() << xml.name();
        }
    }
}
