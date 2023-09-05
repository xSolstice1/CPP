#include "Weather.h"

//default constructor
Weather::Weather()
{
    speed = 0;
    solarRadiation = 0;
    temp = 0;
}

//parametized constructor
Weather::Weather(float s, float sr, float t)
{
    speed = s;
    solarRadiation = sr;
    temp = t;
}

//getter
float Weather::getTemp() const
{
    return temp;
}

float Weather::getSR() const
{
    return solarRadiation;
}

float Weather::getSpeed() const
{
    return speed;
}

//setter
void Weather::setSpeed(float s)
{
    speed = s;
}

void Weather::setSR(float sr)
{
    solarRadiation = sr;
}

void Weather::setTemp(float t)
{
    temp = t;
}

//iostream
istream& operator >> (istream& input, Weather & W)
{
    string data;
    Vector<float> wdata;
    int const NUM_OF_COLUMNS = 17; //enter number of columns excluding date/time

    //enter the index position of speed, sr and temp excluding date/time
    int const SPEED_INDEX = 10;
    int const SR_INDEX = 11;
    int const TEMP_INDEX = 0;

    for(int i=0; i<NUM_OF_COLUMNS-1; i++)
    {
        getline(input,data,',');
        wdata.pushBack(stof(data));
    }
    getline(input,data,'\n');

    W.setSpeed(wdata.At(SPEED_INDEX));
    W.setSR(wdata.At(SR_INDEX));
    W.setTemp(wdata.At(TEMP_INDEX));

    return input;

}


