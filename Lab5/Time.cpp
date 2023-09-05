#include "Time.h"

Time::Time()
{
    hour = 0;
    minute = 0;
}

Time::Time(int h, int m)
{
    hour = h;
    minute = m;
}

int Time::getHour() const
{
    return hour;
}

int Time::getMinute() const
{
    return minute;
}

void Time::setHour(int h)
{
    hour = h;
}

void Time::setMinute(int m)
{
    minute = m;
}

istream & operator >> (istream & input, Time & T)
{
    string h,m;

    getline(input,h,':');
    getline(input,m,',');

    T.setHour(stoi(h));
    T.setMinute(stoi(m));

    return input;
}

ostream & operator << (ostream & os, Time & T)
{
    os << "Time: " << T.getHour() << ":" << T.getMinute() << endl;

    return os;
}


