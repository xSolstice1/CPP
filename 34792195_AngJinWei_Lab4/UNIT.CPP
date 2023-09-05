// UNIT.CPP - Unit class implementation

#include "unit.h"

Unit::Unit()
{
  name = "";
  unitID = "";
  credits = 0;
}

//Unit::Unit(string n, string id, int credit)
//{
//  name = n;
//  unitID = id;
//  credits = credit;

//}

void Unit::setName(string n)
{
    name = n;
}

void Unit::setID(string id)
{
    unitID = id;
}

void Unit::setCredits(int cred)
{
    credits = cred;
}

string Unit::getName() const
{
    return name;
}

string Unit::getID() const
{
    return unitID;
}

int Unit::getCredits() const
{
    return credits;
}

istream & operator >>( istream & input, Unit & U )
{
    string name, id, credits;

    getline(input,name,',');
    getline(input,id,',');
    getline(input,credits,',');

    U.setName(name);
    U.setID(id);
    U.setCredits(stoi(credits));

  return input;
}

ostream & operator <<( ostream & os, const Unit & U )
{
  os << "  Course:  " << U.getName() << '\n'
     << "  Section: " << U.getID() << '\n'
     << "  Credits: " << U.getCredits() << '\n';
  return os;
}
