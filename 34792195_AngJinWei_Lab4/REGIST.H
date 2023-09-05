// REGIST.H - Registration class definition
// author KRI
// modified smr

#ifndef REGIST_H
#define REGIST_H

#include <iostream>
#include "result.h"

using namespace std;

const unsigned MaxResults = 10;

class Registration {
public:
  Registration();

  unsigned GetCredits();
  unsigned GetCount() const;
  long getID() const;
  unsigned getSem() const;
  void setCount(unsigned c);
  void setId(long id);
  void setSem(unsigned sem);
  void setResult(Result r[]);
  Result getResult(int index) const;




private:
  long studentId;             // student ID number
  unsigned semester;          // semester year, number
  unsigned count;             // number of courses
  Result result[MaxResults]; // array of courses
};

ostream & operator <<( ostream & os, Registration & R);

istream & operator >>( istream & input, Registration & R );


#endif

