#include "zipfileheaders.h"

uint16_t CentralDirectory::getVerionMadeBy() const
{
    return verionMadeBy;
}

void CentralDirectory::setVerionMadeBy(uint16_t value)
{
    verionMadeBy = value;
}

uint16_t CentralDirectory::getVersionNeededToExtract() const
{
    return versionNeededToExtract;
}

void CentralDirectory::setVersionNeededToExtract(uint16_t value)
{
    versionNeededToExtract = value;
}

uint16_t CentralDirectory::getGeneralPurposeBitFlag() const
{
    return generalPurposeBitFlag;
}

void CentralDirectory::setGeneralPurposeBitFlag(uint16_t value)
{
    generalPurposeBitFlag = value;
}

uint16_t CentralDirectory::getCompressionMethod() const
{
    return compressionMethod;
}

void CentralDirectory::setCompressionMethod(uint16_t value)
{
    compressionMethod = value;
}

uint16_t CentralDirectory::getLastModFileTime() const
{
    return lastModFileTime;
}

void CentralDirectory::setLastModFileTime(uint16_t value)
{
    lastModFileTime = value;
}

uint16_t CentralDirectory::getLastModFileDate() const
{
    return lastModFileDate;
}

void CentralDirectory::setLastModFileDate(uint16_t value)
{
    lastModFileDate = value;
}

uint32_t CentralDirectory::getCrc32() const
{
    return crc32;
}

void CentralDirectory::setCrc32(uint32_t value)
{
    crc32 = value;
}

uint32_t CentralDirectory::getCompressedSize() const
{
    return compressedSize;
}

void CentralDirectory::setCompressedSize(uint32_t value)
{
    compressedSize = value;
}

uint32_t CentralDirectory::getUncompressedSize() const
{
    return uncompressedSize;
}

void CentralDirectory::setUncompressedSize(uint32_t value)
{
    uncompressedSize = value;
}

uint16_t CentralDirectory::getFileNameLength() const
{
    return fileNameLength;
}

void CentralDirectory::setFileNameLength(uint16_t value)
{
    fileNameLength = value;
}

uint16_t CentralDirectory::getExtraFieldLength() const
{
    return extraFieldLength;
}

void CentralDirectory::setExtraFieldLength(uint16_t value)
{
    extraFieldLength = value;
}

uint16_t CentralDirectory::getFileCommentLength() const
{
    return fileCommentLength;
}

void CentralDirectory::setFileCommentLength(uint16_t value)
{
    fileCommentLength = value;
}

uint16_t CentralDirectory::getDiskNumberStart() const
{
    return diskNumberStart;
}

void CentralDirectory::setDiskNumberStart(uint16_t value)
{
    diskNumberStart = value;
}

uint16_t CentralDirectory::getInternalFileAttributes() const
{
    return internalFileAttributes;
}

void CentralDirectory::setInternalFileAttributes(uint16_t value)
{
    internalFileAttributes = value;
}

uint32_t CentralDirectory::getExternalFileAttributes() const
{
    return externalFileAttributes;
}

void CentralDirectory::setExternalFileAttributes(uint32_t value)
{
    externalFileAttributes = value;
}

uint32_t CentralDirectory::getRelativeOffsetOfLocalHeader() const
{
    return relativeOffsetOfLocalHeader;
}

void CentralDirectory::setRelativeOffsetOfLocalHeader(uint32_t value)
{
    relativeOffsetOfLocalHeader = value;
}

CentralDirectory::CentralDirectory(CentralDirectoryStruct centralDirectoryStruct) :
    CentralDirectoryStruct(centralDirectoryStruct)
{
}

uint32_t CentralDirectory::getSignature() const
{
    return signature;
}

void CentralDirectory::setSignature(uint32_t value)
{
    signature = value;
}

QString CentralDirectory::getFileName() const
{
    return m_fileName;
}

void CentralDirectory::setFileName(const QString &fileName)
{
    m_fileName = fileName;
}

QByteArray CentralDirectory::getExtraField() const
{
    return m_extraField;
}

void CentralDirectory::setExtraField(const QByteArray &extraField)
{
    m_extraField = extraField;
}

QString CentralDirectory::getFileComment() const
{
    return m_fileComment;
}

void CentralDirectory::setFileComment(const QString &fileComment)
{
    m_fileComment = fileComment;
}

uint16_t LocalFile::getVersionNeededToExtract() const
{
    return versionNeededToExtract;
}

void LocalFile::setVersionNeededToExtract(uint16_t value)
{
    versionNeededToExtract = value;
}

uint16_t LocalFile::getGeneralPurposeBitFlag() const
{
    return generalPurposeBitFlag;
}

void LocalFile::setGeneralPurposeBitFlag(uint16_t value)
{
    generalPurposeBitFlag = value;
}

uint16_t LocalFile::getCompressionMethod() const
{
    return compressionMethod;
}

void LocalFile::setCompressionMethod(uint16_t value)
{
    compressionMethod = value;
}

uint16_t LocalFile::getLastModFileTime() const
{
    return lastModFileTime;
}

void LocalFile::setLastModFileTime(uint16_t value)
{
    lastModFileTime = value;
}

uint16_t LocalFile::getLastModFileDate() const
{
    return lastModFileDate;
}

void LocalFile::setLastModFileDate(uint16_t value)
{
    lastModFileDate = value;
}

uint32_t LocalFile::getCrc32() const
{
    return crc32;
}

void LocalFile::setCrc32(uint32_t value)
{
    crc32 = value;
}

uint32_t LocalFile::getCompressedSize() const
{
    return compressedSize;
}

void LocalFile::setCompressedSize(uint32_t value)
{
    compressedSize = value;
}

uint32_t LocalFile::getUncompressedSize() const
{
    return uncompressedSize;
}

void LocalFile::setUncompressedSize(uint32_t value)
{
    uncompressedSize = value;
}

uint16_t LocalFile::getFileNameLength() const
{
    return fileNameLength;
}

void LocalFile::setFileNameLength(uint16_t value)
{
    fileNameLength = value;
}

uint16_t LocalFile::getExtraFieldLength() const
{
    return extraFieldLength;
}

void LocalFile::setExtraFieldLength(uint16_t value)
{
    extraFieldLength = value;
}

QString LocalFile::getFileName() const
{
    return m_fileName;
}

void LocalFile::setFileName(const QString &fileName)
{
    m_fileName = fileName;
}

QByteArray LocalFile::getExtraField() const
{
    return m_extraField;
}

void LocalFile::setExtraField(const QByteArray &extraField)
{
    m_extraField = extraField;
}

LocalFile::LocalFile(LocalFileStruct localFileStruct) :
    LocalFileStruct(localFileStruct)
{
}

uint32_t LocalFile::getLocalFileHeaderSignature() const
{
    return signature;
}

void LocalFile::setLocalFileHeaderSignature(uint32_t value)
{
    signature = value;
}

uint16_t EndOfCentralDirectory::getNumberOfThisDisk() const
{
    return numberOfThisDisk;
}

void EndOfCentralDirectory::setNumberOfThisDisk(uint16_t value)
{
    numberOfThisDisk = value;
}

uint16_t EndOfCentralDirectory::getDiskWhereCentralDirectoryStarts() const
{
    return diskWhereCentralDirectoryStarts;
}

void EndOfCentralDirectory::setDiskWhereCentralDirectoryStarts(uint16_t value)
{
    diskWhereCentralDirectoryStarts = value;
}

uint16_t EndOfCentralDirectory::getNumberOfCentralDirectoryRecordsOnThisDisk() const
{
    return numberOfCentralDirectoryRecordsOnThisDisk;
}

void EndOfCentralDirectory::setNumberOfCentralDirectoryRecordsOnThisDisk(uint16_t value)
{
    numberOfCentralDirectoryRecordsOnThisDisk = value;
}

uint16_t EndOfCentralDirectory::getTotalNumberOfCentralDirectoryRecords() const
{
    return totalNumberOfCentralDirectoryRecords;
}

void EndOfCentralDirectory::setTotalNumberOfCentralDirectoryRecords(uint16_t value)
{
    totalNumberOfCentralDirectoryRecords = value;
}

uint32_t EndOfCentralDirectory::getSizeOfTheCentralDirectory() const
{
    return sizeOfTheCentralDirectory;
}

void EndOfCentralDirectory::setSizeOfTheCentralDirectory(uint32_t value)
{
    sizeOfTheCentralDirectory = value;
}

uint32_t EndOfCentralDirectory::getOffsetOfStartOfCentralDirectoryRelativeToStartOfArchive() const
{
    return offsetOfStartOfCentralDirectoryRelativeToStartOfArchive;
}

void EndOfCentralDirectory::setOffsetOfStartOfCentralDirectoryRelativeToStartOfArchive(uint32_t value)
{
    offsetOfStartOfCentralDirectoryRelativeToStartOfArchive = value;
}

uint16_t EndOfCentralDirectory::getFileCommentLength() const
{
    return fileCommentLength;
}

void EndOfCentralDirectory::setFileCommentLength(uint16_t value)
{
    fileCommentLength = value;
}

QString EndOfCentralDirectory::getComment() const
{
    return m_comment;
}

void EndOfCentralDirectory::setComment(const QString &comment)
{
    m_comment = comment;
}

EndOfCentralDirectory::EndOfCentralDirectory(EndOfCentralDirectoryStruct endOfCentralDirectoryStruct) :
    EndOfCentralDirectoryStruct(endOfCentralDirectoryStruct)
{
}

uint32_t EndOfCentralDirectory::getSignature() const
{
    return signature;
}

void EndOfCentralDirectory::setSignature(uint32_t value)
{
    signature = value;
}

uint32_t DataDescriptor::getCrc32() const
{
    return crc32;
}

void DataDescriptor::setCrc32(uint32_t value)
{
    crc32 = value;
}

uint32_t DataDescriptor::getCompressedSize() const
{
    return compressedSize;
}

void DataDescriptor::setCompressedSize(uint32_t value)
{
    compressedSize = value;
}

uint32_t DataDescriptor::getUncompressedSize() const
{
    return uncompressedSize;
}

void DataDescriptor::setUncompressedSize(uint32_t value)
{
    uncompressedSize = value;
}

uint32_t DataDescriptor::getSignature() const
{
    return signature;
}

void DataDescriptor::setSignature(uint32_t value)
{
    signature = value;
}

UnixExtra::UnixExtra(uint32_t uid, uint32_t gid) :
    signature(0x7875),
    size(11),
    version(1),
    UIDSize(4),
    UID(uid),
    GIDSize(4),
    GID(gid)
{
}
