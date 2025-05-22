#ifndef DATE_H
#define DATE_H
#include <string>
using namespace std;

class Date {
    private:
        int month;
        int day;
        int year;
        int hour;
        int minutes;
    public:
        Date() {month = 0; day = 0; year = 0; hour = 0; minutes = 0;}
        Date(int month, int day, int year, int hour, int minutes) : month(month), day(day), year(year), hour(hour), minutes(minutes) {}
        string formattedDate();
};

#endif

