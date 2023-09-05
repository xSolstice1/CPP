#include "Date.h"

//default constructor
Date::Date()
{
    day = 0;
    month = 0;
    year = 0;
}

//parametized constructor
Date::Date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

//getter
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

//setter
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

//function to return month name corresponding to month number
string Date::monthName(int m)
{
    switch(m)
    {
    case 1:
        return "January";
    case 2:
        return "February";
    case 3:
        return "March";
    case 4:
        return "April";
    case 5:
        return "May";
    case 6:
        return "June";
    case 7:
        return "July";
    case 8:
        return "August";
    case 9:
        return "September";
    case 10:
        return "October";
    case 11:
        return "November";
    case 12:
        return "December";
    }
}

//iostream
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
