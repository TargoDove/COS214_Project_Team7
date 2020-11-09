#include "Date.h"

Date::Date(){
  day = 1;
  month = 1;
  year = 2000;
}

Date::Date(int d, int m, int y){
  if(validDate(d, m, y))
  {
    day = d;
    month = m;
    year = y;
  } else {
    day = 1;
    month = 1;
    year = 2000;
  }
}

Date::Date(const Date &copy)
{
  day = copy.day;
  month = copy.month;
  year = copy.year;
}

Date::~Date(){
  //Do nothing
}

void Date::setDate(int d, int m, int y){
  if (validDate(d, m, y))
  {
    day = d;
    month = m;
    year = y;
  }
}

string Date::dateToString(Date d)
{
  if(!validDate(d)) return "";

  string temp = "";
  if (day < 10)
    temp += "0";
  temp += to_string(day) + "-";
  if (month < 10)
    temp += "0";
  temp += to_string(month) + "-" + to_string(year);
  return temp;
}

int Date::getDay(){
  return day;
}

int Date::getMonth()
{
  return month;
}

int Date::getYear()
{
  return year;
}

void Date::setDay(int d)
{
  if(validDate(d, month, year)){
    day = d;
  }
}

void Date::setMonth(int m)
{
  if (validDate(day, m, year))
  {
    month = m;
  }
}

void Date::setYear(int y)
{
  if (validDate(day, month, y))
  {
    year = y;
  }
}

void Date::incrementDate(int days)
{ 
  int leap = false;
  int daysInYear = 365;

  if(days > 0){
    while(days > 0){
      if (isLeapYear(year))
      {
        leap = true;
        daysInYear = 366;
      } else
      {
        leap = false;
        daysInYear = 365;
      }
      if (days >= daysInYear)
      {
        year++;
        days -= daysInYear;
      }
      else if (day + days > getDaysInMonth(month, leap))
      {
        days -= getDaysInMonth(month, leap);
        month++;
        if (month > 12)
        {
          month -= 12;
          year++;
        }
      }
      else
      {
        day += days;
        days = 0;
      }
    }
  } else if (days < 0){
    while (days < 0)
    {
      if (isLeapYear(year))
      {
        leap = true;
        daysInYear = 366;
      }
      else
      {
        leap = false;
        daysInYear = 365;
      }
      if (days <= -daysInYear)
      {
        year--;
        days += daysInYear;
      }
      else if (day + days < 1)
      {
        month--;
        if(month < 1)
        {
          year--;
          month += 12;
        }
        if (days < -getDaysInMonth(month, isLeapYear(year)))
        {
          days += getDaysInMonth(month, isLeapYear(year));
        }
        else
        {
          day = getDaysInMonth(month, isLeapYear(year)) + day + days;
          days = 0;
        }
      }
      else
      {
        day += days;
        days = 0;
      }
    }
  }
}
//Monday-> 1, Sunday -> 7
int Date::getDayOfWeek()
{
  int dayOfWeek = 6;
  int days = day;
  bool leap = isLeapYear(year);
  for(int i = 1; i < month; i++)
  {
    days+= getDaysInMonth(i, leap);
  }
  int years = year-2000;
  bool sub = false; 
  if (years < 0)
  {
    sub = true;
    years *= -1;
  }
  years = years % 400;
  int rem = years % 100;
  days += ((years - rem) / 100) * (5);

  years = rem;
  rem = years % 4;
  days += ((years - rem) / 4) + years;
  days = days % 7;

  if(sub){
    days = 7 - days;
  }
  dayOfWeek = (dayOfWeek+days)%7 + 1;
  return dayOfWeek; 
}

int Date::getDaysInMonth(int m, bool leapYear){
  if(m <1 || m > 12){
    return 0;
  } else {
    switch (m)
    {
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
      break;
    case 2:
      if(leapYear) return 29;
      else return 28;
      break;
    default:
      return 31;
    }
  }
}

bool Date::validDate(int d, int m, int y)
{
  if (y < 0 || m < 1 || m > 12 || d < 1 || d > 31)
    return false;

  int maxDay = 28;
  if (isLeapYear(y))
  {
    maxDay = 29;
  }

  switch (m)
  {
  case 4:
  case 6:
  case 9:
  case 11:
    if (d > 30)
      return false;
    break;
  case 2:
    if (d > maxDay)
      return false;
    break;
  default:
    //do nothing
  }
  return true;
}

bool Date::validDate(Date d)
{
  return validDate(d.day, d.month, d.year);
}

// Define prefix increment operator.
Date &Date::operator++()
{
  incrementDate(1);
  return *this;
}

// Define postfix increment operator.
Date Date::operator++(int)
{
  Date temp = *this;
  ++*this;
  return temp;
}

// Define prefix decrement operator.
Date &Date::operator--()
{
  incrementDate(-1);
  return *this;
}

// Define postfix decrement operator.
Date Date::operator--(int)
{
  Date temp = *this;
  --*this;
  return temp;
}

// Overloaded assignment
Date &Date::operator=(const Date &date)
{
  day = date.day;
  month = date.month;
  year = date.year;

  return *this;
}

bool Date::isLeapYear(int y)
{
  if(y%400 == 0) return true;
  else if(y%100 == 0) return false;
  else {
    return (y%4 == 0);
  }
}

bool operator==(const Date &d1, const Date &d2)
{
  return ((d1.day == d2.day) && (d1.month == d2.month) && (d1.year == d2.year));
}

bool operator!=(const Date &d1, const Date &d2)
{
  return !(d1 == d2);
}

bool operator>(const Date &d1, const Date &d2)
{
  if(d1.year > d2.year) 
    return true;
  else if (d1.year == d2.year && d1.month > d2.month)
    return true;
  else if (d1.year == d2.year && d1.month == d2.month && d1.day > d2.day)
    return true;
  else 
    return false;
}

bool operator>=(const Date &d1, const Date &d2)
{
  return d1 > d2 || d1 == d2;
}

bool operator<(const Date &d1, const Date &d2)
{
  if (d1.year < d2.year)
    return true;
  else if (d1.year == d2.year && d1.month < d2.month)
    return true;
  else if (d1.year == d2.year && d1.month == d2.month && d1.day < d2.day)
    return true;
  else
    return false;
}

bool operator<=(const Date &d1, const Date &d2)
{
  return d1 < d2 || d1 == d2;
}
