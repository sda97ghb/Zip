#ifndef AUX_H
#define AUX_H

#include <QDateTime>

/**
 * @brief Вспомогательные функции
 */
class aux
{
public:
    static QDateTime dosDateTimeToQDateTime(uint16_t date, uint16_t time);
    static void QDateTimeToDosDateTime(QDateTime dateTime, uint16_t& date, uint16_t& time);
};

#endif // AUX_H
