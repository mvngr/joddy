#ifndef OSMPARSER_H
#define OSMPARSER_H

#include <QFile>
#include <QString>
#include <QDebug>
#include <QXmlStreamReader>
#include <QMessageBox>
#include <joddycontroller.h>

class OsmParser
{
public:
    OsmParser(QString path, JoddyController * controller);

    bool readFile();
private:
    JoddyController * controller_;
    QString path_;
    QFile *file_;
};

#endif // OSMPARSER_H
