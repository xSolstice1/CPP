#include "WindLog.h"

//default constructor
WindLog::WindLog()
{
    m_date = Date(0,0,0);
    m_time = Time(0,0);
    m_weather = Weather(0,0,0);
}

//parametized constructor
WindLog::WindLog(Date d, Time t, Weather w)
{
    m_date = d;
    m_time = t;
    m_weather = w;
}

//Setter
void WindLog::SetDate(Date d)
{
    m_date = d;
}

void WindLog::SetTime(Time t)
{
    m_time = t;
}

void WindLog::SetWeather(Weather w)
{
    m_weather = w;
}

//Getter
Date WindLog::GetDate() const
{
    return m_date;
}

Time WindLog::GetTime() const
{
    return m_time;
}

Weather WindLog::GetWeather() const
{
    return m_weather;
}




