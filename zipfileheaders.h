#ifndef ZIPFILEHEADERS_H
#define ZIPFILEHEADERS_H

#include <QString>
#include <cstdint>

namespace signatures
{
static constexpr uint32_t CENTRAL_DIRECTORY = 0x02014b50;
static constexpr uint32_t LOCAL_FILE = 0x04034b50;
static constexpr uint32_t END_OF_CENTRAL_DIRECTORY = 0x06054b50;
static constexpr uint32_t DATA_DESCRIPTOR = 0x08074b50;
}

#pragma pack(1)

struct CentralDirectoryStruct
{
    uint32_t signature;
    uint16_t verionMadeBy;
    uint16_t versionNeededToExtract;
    uint16_t generalPurposeBitFlag;
    uint16_t compressionMethod;
    uint16_t lastModFileTime;
    uint16_t lastModFileDate;
    uint32_t crc32;
    uint32_t compressedSize;
    uint32_t uncompressedSize;
    uint16_t fileNameLength;
    uint16_t extraFieldLength;
    uint16_t fileCommentLength;
    uint16_t diskNumberStart;
    uint16_t internalFileAttributes;
    uint32_t externalFileAttributes;
    uint32_t relativeOffsetOfLocalHeader;
};

class CentralDirectory : private CentralDirectoryStruct
{
public:
    CentralDirectory() = default;
    CentralDirectory(CentralDirectoryStruct centralDirectoryStruct);

    uint32_t getSignature() const;
    void setSignature(uint32_t value);

    uint16_t getVerionMadeBy() const;
    void setVerionMadeBy(uint16_t value);

    uint16_t getVersionNeededToExtract() const;
    void setVersionNeededToExtract(uint16_t value);

    uint16_t getGeneralPurposeBitFlag() const;
    void setGeneralPurposeBitFlag(uint16_t value);

    uint16_t getCompressionMethod() const;
    void setCompressionMethod(uint16_t value);

    uint16_t getLastModFileTime() const;
    void setLastModFileTime(uint16_t value);

    uint16_t getLastModFileDate() const;
    void setLastModFileDate(uint16_t value);

    uint32_t getCrc32() const;
    void setCrc32(uint32_t value);

    uint32_t getCompressedSize() const;
    void setCompressedSize(uint32_t value);

    uint32_t getUncompressedSize() const;
    void setUncompressedSize(uint32_t value);

    uint16_t getFileNameLength() const;
    void setFileNameLength(uint16_t value);

    uint16_t getExtraFieldLength() const;
    void setExtraFieldLength(uint16_t value);

    uint16_t getFileCommentLength() const;
    void setFileCommentLength(uint16_t value);

    uint16_t getDiskNumberStart() const;
    void setDiskNumberStart(uint16_t value);

    uint16_t getInternalFileAttributes() const;
    void setInternalFileAttributes(uint16_t value);

    uint32_t getExternalFileAttributes() const;
    void setExternalFileAttributes(uint32_t value);

    uint32_t getRelativeOffsetOfLocalHeader() const;
    void setRelativeOffsetOfLocalHeader(uint32_t value);

    QString getFileName() const;
    void setFileName(const QString &fileName);

    QByteArray getExtraField() const;
    void setExtraField(const QByteArray &extraField);

    QString getFileComment() const;
    void setFileComment(const QString &fileComment);

private:
    QString m_fileName;
    QByteArray m_extraField;
    QString m_fileComment;
};

struct LocalFileStruct
{
    uint32_t signature;
    uint16_t versionNeededToExtract;
    uint16_t generalPurposeBitFlag;
    uint16_t compressionMethod;
    uint16_t lastModFileTime;
    uint16_t lastModFileDate;
    uint32_t crc32;
    uint32_t compressedSize;
    uint32_t uncompressedSize;
    uint16_t fileNameLength;
    uint16_t extraFieldLength;
};

class LocalFile : private LocalFileStruct
{
public:
    LocalFile() = default;
    LocalFile(LocalFileStruct localFileStruct);

    uint32_t getLocalFileHeaderSignature() const;
    void setLocalFileHeaderSignature(uint32_t value);

    uint16_t getVersionNeededToExtract() const;
    void setVersionNeededToExtract(uint16_t value);

    uint16_t getGeneralPurposeBitFlag() const;
    void setGeneralPurposeBitFlag(uint16_t value);

    uint16_t getCompressionMethod() const;
    void setCompressionMethod(uint16_t value);

    uint16_t getLastModFileTime() const;
    void setLastModFileTime(uint16_t value);

    uint16_t getLastModFileDate() const;
    void setLastModFileDate(uint16_t value);

    uint32_t getCrc32() const;
    void setCrc32(uint32_t value);

    uint32_t getCompressedSize() const;
    void setCompressedSize(uint32_t value);

    uint32_t getUncompressedSize() const;
    void setUncompressedSize(uint32_t value);

    uint16_t getFileNameLength() const;
    void setFileNameLength(uint16_t value);

    uint16_t getExtraFieldLength() const;
    void setExtraFieldLength(uint16_t value);

    QString getFileName() const;
    void setFileName(const QString &fileName);

    QByteArray getExtraField() const;
    void setExtraField(const QByteArray &extraField);

private:
    QString m_fileName;
    QByteArray m_extraField;
};

struct EndOfCentralDirectoryStruct
{
    uint32_t signature;
    uint16_t numberOfThisDisk;
    uint16_t diskWhereCentralDirectoryStarts;
    uint16_t numberOfCentralDirectoryRecordsOnThisDisk;
    uint16_t totalNumberOfCentralDirectoryRecords;
    uint32_t sizeOfTheCentralDirectory;
    uint32_t offsetOfStartOfCentralDirectoryRelativeToStartOfArchive;
    uint16_t fileCommentLength;
};

class EndOfCentralDirectory : private EndOfCentralDirectoryStruct
{
public:
    EndOfCentralDirectory() = default;
    EndOfCentralDirectory(EndOfCentralDirectoryStruct endOfCentralDirectoryStruct);

    uint32_t getSignature() const;
    void setSignature(uint32_t value);

    uint16_t getNumberOfThisDisk() const;
    void setNumberOfThisDisk(uint16_t value);

    uint16_t getDiskWhereCentralDirectoryStarts() const;
    void setDiskWhereCentralDirectoryStarts(uint16_t value);

    uint16_t getNumberOfCentralDirectoryRecordsOnThisDisk() const;
    void setNumberOfCentralDirectoryRecordsOnThisDisk(uint16_t value);

    uint16_t getTotalNumberOfCentralDirectoryRecords() const;
    void setTotalNumberOfCentralDirectoryRecords(uint16_t value);

    uint32_t getSizeOfTheCentralDirectory() const;
    void setSizeOfTheCentralDirectory(uint32_t value);

    uint32_t getOffsetOfStartOfCentralDirectoryRelativeToStartOfArchive() const;
    void setOffsetOfStartOfCentralDirectoryRelativeToStartOfArchive(uint32_t value);

    uint16_t getFileCommentLength() const;
    void setFileCommentLength(uint16_t value);

    QString getComment() const;
    void setComment(const QString &comment);

private:
    QString m_comment;
};

struct DataDescriptorStruct
{
    uint32_t signature;
    uint32_t crc32;
    uint32_t compressedSize;
    uint32_t uncompressedSize;
};

class DataDescriptor : private DataDescriptorStruct
{
public:
    DataDescriptor() = default;
    DataDescriptor(DataDescriptorStruct dataDescriptorStruct);

    uint32_t getSignature() const;
    void setSignature(uint32_t value);

    uint32_t getCrc32() const;
    void setCrc32(uint32_t value);

    uint32_t getCompressedSize() const;
    void setCompressedSize(uint32_t value);

    uint32_t getUncompressedSize() const;
    void setUncompressedSize(uint32_t value);
};

struct UnixExtra
{
    uint16_t signature;
    uint16_t size;
    uint8_t  version;
    uint8_t  UIDSize;
    uint32_t UID;
    uint8_t  GIDSize;
    uint32_t GID;

    UnixExtra(uint32_t uid, uint32_t gid);
};

#endif // ZIPFILEHEADERS_H
