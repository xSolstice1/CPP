#ifndef RESULT_H
#define RESULT_H

#include "unit.h"
#include "Date.h"
#include <iostream>

using namespace std;


class Result
{
    public:
        Result();

        Result(Unit &unit, float marks);

        Unit getUnit() const;

        Date getDate() const;

        void setUnit(Unit unit);

        void setDate(Date d);

        float getMark();

        void setMark(float marks);

        int getCredits() const;

    protected:

    private:
        Unit obj;
        Date dobj;
        float mark;
};

ostream & operator <<( ostream & os, Result & result);

istream & operator >>( istream & input, Result & result);

#endif // RESULT_H
