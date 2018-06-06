#include "aux.h"

QDateTime aux::dosDateTimeToQDateTime(uint16_t date, uint16_t time)
{
    int hour = (time >> 11);
    int minute = ((time >> 5) & 0x3F);
    int second = (time & 0x1F) * 2;

    int day = (date & 0x1F);
    int month = ((date >> 5) & 0x0F);
    int year = ((date >> 9) & 0x7F) + 1980;

    return QDateTime(QDate(year, month, day),
                     QTime(hour, minute, second));
}

void aux::QDateTimeToDosDateTime(QDateTime dateTime, uint16_t& date, uint16_t& time)
{
    date = ((dateTime.date().year() - 1980) << 9) |
            (dateTime.date().month() << 5) |
            (dateTime.date().day());
    time = (dateTime.time().hour() << 11) |
            (dateTime.time().minute() << 5) |
            (dateTime.time().second() / 2);
}
