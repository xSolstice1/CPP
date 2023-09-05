#include "Weather.h"

//default constructor
Weather::Weather()
{
    m_speed = 0;
    m_solarRadiation = 0;
    m_temp = 0;
}

//parametized constructor
Weather::Weather(float s, float sr, float t)
{
    m_speed = s;
    m_solarRadiation = sr;
    m_temp = t;
}

//getter
float Weather::GetTemp() const
{
    return m_temp;
}

float Weather::GetSR() const
{
    return m_solarRadiation;
}

float Weather::GetSpeed() const
{
    return m_speed;
}

//setter
void Weather::SetSpeed(float s)
{
    m_speed = s;
}

void Weather::SetSR(float sr)
{
    m_solarRadiation = sr;
}

void Weather::SetTemp(float t)
{
    m_temp = t;
}


