#include "Result.h"

Result::Result()
{
    mark = 0;
}

Result::Result(Unit &unit, float marks)
{
    obj = unit;
    mark = marks;
}

Unit Result::getUnit() const
{
    return obj;
}

Date Result::getDate() const
{
    return dobj;
}

float Result::getMark()
{
    return mark;
}

int Result::getCredits() const
{
    return obj.getCredits();
}

void Result::setUnit(Unit unit)
{
    obj = unit;
}

void Result::setMark(float marks)
{
    mark = marks;
}

void Result::setDate(Date d)
{
    dobj = d;
}

istream & operator >> (istream & input, Result &result)
{
    Unit myUnit;
    string mark;
    Date myDate;

    input >> myUnit;
    result.setUnit(myUnit);

    getline(input,mark,',');
    result.setMark(stof(mark));

    input >> myDate;
    result.setDate(myDate);

    cout << myUnit << "  Marks: " << mark << "\n" << myDate << endl;

    return input;
}

ostream & operator <<(ostream & os, Result &result)
{

    Date newDate;
    newDate = result.getDate();

    os << result.getUnit() << "  Marks:  " << result.getMark() << "\n" << newDate << endl;
    return os;
}
