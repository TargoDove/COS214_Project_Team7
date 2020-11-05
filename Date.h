#ifndef DATE_H
#define DATE_H

#include <string>

using namespace std;

class Date
{
	public:
    Date();
    Date(int d, int m, int y);
    ~Date();
    void setDate(int d, int m, int y);
    string dateToString(Date d);
    int getDay();
    int getMonth();
    int getYear();
    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);
    void incrementDate(int days);
    int getDayOfWeek();
    int getDaysInMonth(int m, bool leapYear);
    bool validDate(int d, int m, int y);
    bool validDate(Date d);
    bool isLeapYear(int y);

    // Declare prefix and postfix increment operators.
    Date &operator++();    // Prefix increment operator.
    Date operator++(int);  // Postfix increment operator.
    // Declare prefix and postfix decrement operators.
    Date &operator--();    // Prefix decrement operator.
    Date operator--(int);  // Postfix decrement operator.
  private:
    int day;
    int month;
    int year;
};

#endif
