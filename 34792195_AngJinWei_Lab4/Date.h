#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>

using namespace std;


class Date
{
    public:
        Date();
        int getDay();
        string getMonth();
        int getYear();
        void setDay(int d);
        void setMonth(string m);
        void setYear(int y);


    protected:

    private:
        int day;
        string month;
        int year;
};

ostream & operator << (ostream & os, Date & D);

istream & operator >> (istream & input, Date & D);

#endif // DATE_H
