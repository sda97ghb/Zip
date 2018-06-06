#ifndef ZIPDIR_H
#define ZIPDIR_H

#include <QString>

/**
 * @brief Собирает файлы из директории в zip архив
 */
class ZipDir
{
public:
    ZipDir(QString dir, QString output);

    void execute();

private:
    QString m_dir;
    QString m_output;
};

#endif // ZIPDIR_H
