#include "Date.h"

Date::Date()
{
    day = 0;
    month = "";
    year = 0;
}

int Date::getDay()
{
    return day;
}

string Date::getMonth()
{
    return month;
}

int Date::getYear()
{
    return year;
}

void Date::setDay(int d)
{
    day = d;
}

void Date::setMonth(string m)
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

    getline(input,d,',');
    getline(input,m,',');
    getline(input,y);

    D.setDay(stoi(d));
    D.setMonth(m);
    D.setYear(stoi(y));

    return input;
}

ostream & operator << (ostream & os, Date & D)
{
  os << "  Date Obtained:  " <<  D.getDay() << " " << D.getMonth() << " " << D.getYear() << endl;

  return os;
}
