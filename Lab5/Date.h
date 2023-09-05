#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>

using namespace std;


class Date
{
    public:
        Date();
        Date(int d, int m, int y);
        int getDay() const;
        int getMonth() const;
        int getYear() const;
        void setDay(int d);
        void setMonth(int m);
        void setYear(int y);


    protected:

    private:
        int day;
        int month;
        int year;
};

ostream & operator << (ostream & os, Date & D);

istream & operator >> (istream & input, Date & D);

#endif // DATE_H
