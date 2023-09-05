#include "Date.h"

Date::Date()
{
    day = 0;
    month = 0;
    year = 0;
}

Date::Date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

int Date::getDay() const
{
    return day;
}

int Date::getMonth() const
{
    return month;
}

int Date::getYear() const
{
    return year;
}

void Date::setDay(int d)
{
    day = d;
}

void Date::setMonth(int m)
{
    month = m;
}

void Date::setYear(int y)
{
    year = y;
}

istream & operator >>(istream & input, Date & D)
{
    string d,m,y;

    getline(input,d,'/');
    getline(input,m,'/');
    getline(input,y,' ');

    D.setDay(stoi(d));
    D.setMonth(stoi(m));
    D.setYear(stoi(y));

    return input;
}

ostream & operator << (ostream & os, Date & D)
{
  os << "  Date Obtained:  " <<  D.getDay() << " " << D.getMonth() << " " << D.getYear() << endl;

  return os;
}
