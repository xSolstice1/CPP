// COURSE.H - Course class definition
// author KRI
// modified smr

#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string.h>  // C string library

using namespace std;

const unsigned CourseNameSize = 10;

class Unit {
public:
  Unit();
  Unit( const char * nam, char sect, unsigned cred );
  // Construct a course from a name, section letter,
  // and number of credits.

  string getName() const;

  void setName(string n);

  string getID() const;

  void setID(string id);

  int getCredits() const;

  void setCredits(int cred );
  // Set the number of credits.


private:
  string name;  // unit name
  string unitID;   // unit ID
  int  credits;   // number of credits
};

ostream & operator <<( ostream & os, const Unit & U );
istream & operator >>( istream & input, Unit & U );

#endif
