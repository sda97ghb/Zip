#include "zipfileheaders.h"
#include "zipparser.h"

#include <QDataStream>
#include <QDateTime>
#include <QFile>

#include <QtDebug>

Unzip::Unzip(QString filename) :
    m_filename(filename)
{
}

void Unzip::execute()
{
    m_file.reset(new QFile(m_filename));
    if (!m_file->open(QIODevice::ReadOnly))
    {
        qDebug() << "Sorry, can't open";
        return;
    }

    m_stream.reset(new QDataStream(m_file.data()));

    uint32_t signature;

    while (!m_stream->atEnd())
    {
        m_stream->startTransaction();
        m_stream->readRawData(reinterpret_cast<char*>(&signature), 4);
        m_stream->rollbackTransaction();

        switch (signature)
        {
        case signatures::CENTRAL_DIRECTORY:
            parseCentralDirectory();
            break;
        case signatures::LOCAL_FILE:
            parseLocalFile();
            break;
        case signatures::END_OF_CENTRAL_DIRECTORY:
            parseEndOfCetralDirectory();
            break;
        case signatures::DATA_DESCRIPTOR:
            parseDataDescriptors();
            break;
        default:
            break;
        }
        qDebug() << signature;
    }
}

void Unzip::parseLocalFile()
{
    LocalFileStruct localFileStruct;

    m_stream->readRawData(reinterpret_cast<char*>(&localFileStruct), sizeof(localFileStruct));
    char* fileNameBuf = new char[localFileStruct.fileNameLength];
    char* extraFieldBuf = new char[localFileStruct.extraFieldLength];
    m_stream->readRawData(fileNameBuf, localFileStruct.fileNameLength);
    m_stream->readRawData(extraFieldBuf, localFileStruct.extraFieldLength);

    LocalFile localFile(localFileStruct);
    localFile.setFileName(QString::fromLatin1(fileNameBuf, localFileStruct.fileNameLength));
    localFile.setExtraField(QByteArray::fromRawData(extraFieldBuf, localFileStruct.extraFieldLength));

    m_localFiles.append(localFile);

    uint16_t dos_time = localFileStruct.lastModFileTime;
    uint16_t dos_seconds = (dos_time & 0b0000'0000'0001'1111) << 1;
                            uint16_t dos_minutes = (dos_time & 0b0000'1111'1110'1111) >> 5;
                                                    uint16_t dos_hours   = (dos_time & 0b1111'0000'0000'0000) >> 11;
}

void Unzip::parseCentralDirectory()
{
    CentralDirectoryStruct centralDirectoryStruct;
    m_stream->readRawData(reinterpret_cast<char*>(&centralDirectoryStruct), sizeof(centralDirectoryStruct));

}

void Unzip::parseDataDescriptors()
{
    DataDescriptorStruct dataDescriptorStruct;
    m_stream->readRawData(reinterpret_cast<char*>(&dataDescriptorStruct), sizeof(dataDescriptorStruct));

}

void Unzip::parseEndOfCetralDirectory()
{
    EndOfCentralDirectoryStruct endOfCentralDirectoryStruct;
    m_stream->readRawData(reinterpret_cast<char*>(&endOfCentralDirectoryStruct), sizeof(endOfCentralDirectoryStruct));

}
