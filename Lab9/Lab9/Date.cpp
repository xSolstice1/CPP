#include "Date.h"

//default constructor
Date::Date()
{
    m_day = 0;
    m_month = 0;
    m_year = 0;
}

//parametized constructor
Date::Date(int d, int m, int y)
{
    m_day = d;
    m_month = m;
    m_year = y;
}

//getter
int Date::GetDay() const
{
    return m_day;
}

int Date::GetMonth() const
{
    return m_month;
}

int Date::GetYear() const
{
    return m_year;
}

//setter
void Date::SetDay(int d)
{
    m_day = d;
}

void Date::SetMonth(int m)
{
    m_month = m;
}

void Date::SetYear(int y)
{
    m_year = y;
}

//function to return month name corresponding to month number
string Date::MonthName(int m) const
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
    default:
        return "Invalid Month!";
    }
}

bool Date::operator > (const Date &date) const
{
    return ((m_year > date.GetYear())) ||
    (m_year > date.GetYear() && m_month > date.GetMonth()) ||
    (m_year > date.GetYear() && m_month > date.GetMonth() && m_day > date.GetDay());
}

//iostream
istream & operator >>(istream & input, Date & D)
{
    string d,m,y;

    getline(input,d,'/');
    getline(input,m,'/');
    getline(input,y,' ');

    D.SetDay(stoi(d));
    D.SetMonth(stoi(m));
    D.SetYear(stoi(y));

    return input;
}

ostream & operator << (ostream & os, Date & D)
{
  os << "  Date:  " <<  D.GetDay() << " " << D.GetMonth() << " " << D.GetYear() << endl;

  return os;
}
