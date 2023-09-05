#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <string>

using namespace std;


class Time
{
    public:
        Time();
        Time(int h, int m);

        int getHour() const;
        int getMinute() const;

        void setHour(int h);
        void setMinute(int m);

    protected:

    private:
        int hour;
        int minute;
};

ostream & operator << (ostream & os, Time & T);
istream & operator >> (istream & input, Time & T);

#endif // TIME_H
