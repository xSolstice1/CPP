#ifndef WEATHER_H
#define WEATHER_H
#include <iostream>
#include <cmath>

#include "WindLog.h"


class Weather
{
    public:
        Weather();
        Weather(float s, float sd);
        Vector<WindLog> getVector();
        void calAvgSpeed(Vector<WindLog> vec);
        float calSD(Vector<WindLog> vec);
        float setAvgSpeed(float& s);
        float setSD(float& sd);
        float getAvgSpeed();
        float getSD();


    protected:

    private:
        float avgSpeed;
        float speedStDev;
        Vector<WindLog> wVector;
};

#endif // WEATHER_H
