#include "WindLog.h"

//default constructor
WindLog::WindLog()
{
    date = Date(0,0,0);
    time = Time(0,0);
    weather = Weather(0,0,0);
}

//parametized constructor
WindLog::WindLog(Date d, Time t, Weather w)
{
    date = d;
    time = t;
}

//Setter
void WindLog::setDate(Date d)
{
    date = d;
}

void WindLog::setTime(Time t)
{
    time = t;
}

void WindLog::setWeather(Weather w)
{
    weather = w;
}

//Getter
Date WindLog::getDate() const
{
    return date;
}

Time WindLog::getTime() const
{
    return time;
}

Weather WindLog::getWeather() const
{
    return weather;
}

//iostream
ostream& operator << (ostream& os, const WindLog& W)
{


    return os;
}

istream& operator >> (istream& input, WindLog & W)
{
    Date d;
    Time t;
    Weather w;

    input >> d;
    W.setDate(d);
    input >> t;
    W.setTime(t);
    input >> w;
    W.setWeather(w);


    return input;

}



