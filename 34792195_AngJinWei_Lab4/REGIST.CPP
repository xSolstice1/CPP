// REGIST.CPP - Registration class implementation.

#include "regist.h"
#include "result.h"
#include <string>


Registration::Registration()
{
  count = 0;
}

unsigned Registration::GetCredits()
{
  unsigned sum = 0;
  for(unsigned i = 0; i < count; i++)
    sum += result[i].getCredits();

  return sum;
}

unsigned Registration::GetCount() const
{
  return count;
}

unsigned Registration::getSem() const
{
    return semester;
}

long Registration::getID() const
{
    return studentId;
}

Result Registration::getResult(int index) const
{
    return result[index];
}

void Registration::setCount(unsigned c)
{
    count = c;
}

void Registration::setId(long id)
{
    studentId = id;
}

void Registration::setSem(unsigned sem)
{
    semester = sem;
}

void Registration::setResult(Result r[])
{
    for (int i = 0; i < GetCount(); i++)
    {
        result[i] = r[i];
    }
}

istream & operator >>( istream & input, Registration & R )
{
    string id,semester,counts;
    Result newR[MaxResults];

    getline(input,id,',');
    getline(input,semester,',');
    getline(input,counts);

    R.setId(stol(id));
    R.setSem(stoi(semester));
    R.setCount(stoi(counts));

    for(unsigned i = 0; i < R.GetCount(); i++)
    {
        input >> newR[i];
    }

    R.setResult(newR);


  return input;
}

ostream & operator <<( ostream & os, Registration & R)

{
  os << "Student ID: " << R.getID() << '\n'
     << "Semester:   " << R.getSem() << '\n';


    for(int i = 0; i < R.GetCount(); i++)
    {
        Result newResult;
        newResult = R.getResult(i);
        os << newResult << endl;
    }

  return os;
}
