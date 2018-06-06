#ifndef ZIPPARSER_H
#define ZIPPARSER_H

#include "zipfileheaders.h"

#include <QDataStream>
#include <QFile>
#include <QString>

class Unzip
{
public:
    Unzip(QString filename);

    void execute();

private:
    void parseLocalFile();
    void parseCentralDirectory();
    void parseDataDescriptors();
    void parseEndOfCetralDirectory();

    QString m_filename;

    QScopedPointer<QFile> m_file;
    QScopedPointer<QDataStream> m_stream;

    QList<LocalFile> m_localFiles;
    QList<CentralDirectory> m_centralDirectories;
    QList<DataDescriptor> m_dataDescriptors;
    QList<EndOfCentralDirectory> m_EndOfCentralDirectories;
};

#endif // ZIPPARSER_H
