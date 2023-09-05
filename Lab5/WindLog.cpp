#include "WindLog.h"

WindLog::WindLog()
{
    date = Date(0,0,0);
    time = Time(0,0);
    speed = 0;
}

WindLog::WindLog(Date d, Time t, float s)
{
    date = d;
    time = t;
    speed = s;
}

void WindLog::setDate(Date d)
{
    date = d;
}

void WindLog::setTime(Time t)
{
    time = t;
}

void WindLog::setSpeed(float s)
{
    speed = s;
}

void WindLog::setData(Vector<float> m_winddata)
{
    winddata = m_winddata;
}

void WindLog::getDate(Date &d) const
{
    d = date;
}

void WindLog::getTime(Time &t) const
{
    t = time;
}

float WindLog::getData(int n) const
{
    return winddata.At(n);
}

float WindLog::getSpeed() const
{
    return speed;
}

ostream& operator << (ostream& os, const WindLog& W)
{
    Date d;
    Time t;
    W.getDate(d);
    W.getTime(t);

    os << "Date: " << d << "\n" << "Time: " << t << "\n" << "Speed: " << W.getSpeed()
    << "\n" << endl;

    return os;
}

istream& operator >> (istream& input, WindLog & W)
{
    Date d;
    Time t;
    string data;
    Vector<float> wdata;
    int NUM_OF_COLUMNS = 16;

    input >> d;
    W.setDate(d);
    input >> t;
    W.setTime(t);

    for(int i=0; i<NUM_OF_COLUMNS+1; i++)
    {
        getline(input,data,',');
        wdata.pushBack(stof(data));
    }
    getline(input,data);

    W.setData(wdata);
    W.setSpeed(W.getData(10));

    return input;

}



