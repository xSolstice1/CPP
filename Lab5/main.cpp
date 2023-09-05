#include "Date.h"
#include "Time.h"
#include "Vector.h"
#include "WindLog.h"
#include "Weather.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    WindLog windObj;
    Weather weatherObj;
    Vector<WindLog> wVector;

   ifstream infile("Data/Test.csv" );
    if(!infile)
    {
        cout << "Error reading file!";
        return -1;
    }
    else
    {
        string line;
        getline(infile, line);
        ofstream ofile( "routput.txt" );
        while (!infile.eof())
        {
            infile >> windObj;
            weatherObj.getVector().pushBack(windObj);

        }
        weatherObj.calSD(weatherObj.getVector());
        weatherObj.calSD(weatherObj.getVector());
        cout << weatherObj.getAvgSpeed() << " " << weatherObj.getSD() << endl;
    }
}
