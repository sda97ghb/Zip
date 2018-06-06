#include "aux.h"
#include "zipdir.h"
#include "zipfileheaders.h"

#include <QDirIterator>

#include <QDataStream>
#include <QtDebug>

static void generate_table(uint32_t(&table)[256])
    {
        uint32_t polynomial = 0xEDB88320;
        for (uint32_t i = 0; i < 256; i++)
        {
            uint32_t c = i;
            for (size_t j = 0; j < 8; j++)
            {
                if (c & 1) {
                    c = polynomial ^ (c >> 1);
                }
                else {
                    c >>= 1;
                }
            }
            table[i] = c;
        }
}

static uint32_t update(uint32_t (&table)[256], uint32_t initial, const void* buf, size_t len)
{
    uint32_t c = initial ^ 0xFFFFFFFF;
    const uint8_t* u = static_cast<const uint8_t*>(buf);
    for (size_t i = 0; i < len; ++i)
    {
        c = table[(c ^ u[i]) & 0xFF] ^ (c >> 8);
    }
    return c ^ 0xFFFFFFFF;
}

ZipDir::ZipDir(QString dir, QString output) :
    m_dir(dir),
    m_output(output)
{
}

void ZipDir::execute()
{
    QFile zipArchiveFile(m_output);
    zipArchiveFile.open(QIODevice::WriteOnly);
    QDataStream stream(&zipArchiveFile);

    uint8_t UT[13] = {0x55, 0x54, 0x09, 0x00, 0x03, 0xE4, 0x99, 0xE5, 0x5A, 0x32, 0x4E, 0x0D, 0x5B};
    UnixExtra unixExtra(1000, 1000);

    QList<CentralDirectory> centralDirectories;

    QDirIterator iter(m_dir, QDir::Dirs | QDir::NoDotAndDotDot | QDir::Files, QDirIterator::Subdirectories);
    while (iter.hasNext()) {
        QString file = iter.next();
        QFile file2(file);
        file2.open(QIODevice::ReadOnly);
        QByteArray data = file2.readAll();

        QFileInfo fileinfo(file);
        QString zipFile = QStringRef(&file, m_dir.length() + 1, file.length() - m_dir.length() - 1) + (fileinfo.isDir() ? "/" : "");
        qDebug() << file << zipFile;

        LocalFileStruct localFile;
        localFile.signature = signatures::LOCAL_FILE;
        localFile.versionNeededToExtract = 10;
        localFile.generalPurposeBitFlag = 0;
        localFile.compressionMethod = 0;
        aux::QDateTimeToDosDateTime(fileinfo.lastModified(),
                                    localFile.lastModFileDate,
                                    localFile.lastModFileTime);
        uint32_t table[256];
        generate_table(table);
        localFile.crc32 = update(table, 0, data.data(), data.length());
        localFile.compressedSize = fileinfo.size();
        localFile.uncompressedSize = fileinfo.size();
        localFile.fileNameLength = zipFile.length();
        localFile.extraFieldLength = 28;

        CentralDirectoryStruct centralDirectoryStruct;
        centralDirectoryStruct.signature = signatures::CENTRAL_DIRECTORY;
        centralDirectoryStruct.verionMadeBy = 798;
        centralDirectoryStruct.versionNeededToExtract = localFile.versionNeededToExtract;
        centralDirectoryStruct.generalPurposeBitFlag = localFile.generalPurposeBitFlag;
        centralDirectoryStruct.compressionMethod = localFile.compressionMethod;
        centralDirectoryStruct.lastModFileDate = localFile.lastModFileDate;
        centralDirectoryStruct.lastModFileTime = localFile.lastModFileTime;
        centralDirectoryStruct.crc32 = localFile.crc32;
        centralDirectoryStruct.compressedSize = localFile.compressedSize;
        centralDirectoryStruct.uncompressedSize = localFile.uncompressedSize;
        centralDirectoryStruct.fileNameLength = localFile.fileNameLength;
        centralDirectoryStruct.extraFieldLength = localFile.extraFieldLength;
        centralDirectoryStruct.fileCommentLength = 0;
        centralDirectoryStruct.diskNumberStart = 0;
        centralDirectoryStruct.internalFileAttributes = 0;
        centralDirectoryStruct.externalFileAttributes = 0;
        centralDirectoryStruct.relativeOffsetOfLocalHeader = zipArchiveFile.pos();

        CentralDirectory centralDirectory(centralDirectoryStruct);
        centralDirectory.setFileName(zipFile);
        centralDirectories.append(centralDirectory);

        stream.writeRawData(reinterpret_cast<char*>(&localFile), sizeof(localFile));
        stream.writeRawData(zipFile.toStdString().c_str(), zipFile.length());
        stream.writeRawData(reinterpret_cast<char*>(UT), 13);
        stream.writeRawData(reinterpret_cast<char*>(&unixExtra), sizeof(UnixExtra));

        stream.writeRawData(data.data(), data.length());
    }

    int start = int(zipArchiveFile.pos());
    for (CentralDirectory centralDirectory : centralDirectories)
    {
        stream.writeRawData(reinterpret_cast<char*>(&centralDirectory), sizeof(CentralDirectoryStruct));
        stream.writeRawData(centralDirectory.getFileName().toStdString().c_str(), centralDirectory.getFileName().length());
        stream.writeRawData(reinterpret_cast<char*>(UT), 13);
        stream.writeRawData(reinterpret_cast<char*>(&unixExtra), sizeof(UnixExtra));
    }
    int sizeOfTheCentralDirectory = int(zipArchiveFile.pos()) - start;

    EndOfCentralDirectoryStruct endOfCentralDirectoryStruct;
    endOfCentralDirectoryStruct.signature = signatures::END_OF_CENTRAL_DIRECTORY;
    endOfCentralDirectoryStruct.numberOfThisDisk = 0;
    endOfCentralDirectoryStruct.diskWhereCentralDirectoryStarts = 0;
    endOfCentralDirectoryStruct.numberOfCentralDirectoryRecordsOnThisDisk = centralDirectories.size();
    endOfCentralDirectoryStruct.totalNumberOfCentralDirectoryRecords = centralDirectories.size();
    endOfCentralDirectoryStruct.sizeOfTheCentralDirectory = sizeOfTheCentralDirectory;
    endOfCentralDirectoryStruct.offsetOfStartOfCentralDirectoryRelativeToStartOfArchive = start;
    endOfCentralDirectoryStruct.fileCommentLength = 0;

    stream.writeRawData(reinterpret_cast<char*>(&endOfCentralDirectoryStruct), sizeof(EndOfCentralDirectory));
}
