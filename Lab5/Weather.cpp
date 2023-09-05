#include "Weather.h"

Weather::Weather()
{
    avgSpeed = 0;
    speedStDev = 0;
}

Weather::Weather(float s, float sd)
{
    avgSpeed = s;
    speedStDev = sd;
}

Vector<WindLog> Weather::getVector()
{
    return wVector;
}

float Weather::setAvgSpeed(float& s)
{
    avgSpeed = s;
}

float Weather::setSD(float& sd)
{
    speedStDev = sd;
}

void Weather::calAvgSpeed(Vector<WindLog> vec)
{
    float total;
    int count;
    float avg;

    for (int i=0; i<vec.Size(); i++){
        total += vec.At(i).getSpeed();
        count += 1;
    }

    avg = total/count;
    setAvgSpeed(avg);
}

float Weather::calSD(Vector<WindLog> vec)
{
    float sum = 0.0;
    float mean;
    float SD = 0.0;

    for (int i=0; i<vec.Size(); i++)
    {
        sum += vec.At(i).getSpeed();
    }

    mean = sum/10;

    for (int i=0; i<vec.Size(); i++)
    {
        SD += pow(vec.At(i).getSpeed() - mean, 2);
    }

    SD = sqrt(SD/10);

    setSD(SD);
}

float Weather::getAvgSpeed()
{
    return avgSpeed;
}

float Weather::getSD()
{
    return speedStDev;
}
