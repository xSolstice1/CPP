#ifndef WINDLOG_H
#define WINDLOG_H

#include <iostream>
#include "Date.h"
#include "Time.h"
#include "Vector.h"


class WindLog
{
    public:
        WindLog();

        WindLog(Date d, Time t, float s);

        void setDate(Date d);

        void setTime(Time t);

        void setSpeed(float s);

        void setData(Vector<float> m_winddata);

        void getDate(Date &d) const;

        void getTime(Time &t) const;

        float getData(int n) const;

        float getSpeed() const;


    private:
        Date date;
        Time time;
        float speed;
        Vector<float> winddata;
};

ostream& operator << (ostream& os, const WindLog& W);
istream& operator >> (istream& input, WindLog& W);

#endif // WINDLOG_H
