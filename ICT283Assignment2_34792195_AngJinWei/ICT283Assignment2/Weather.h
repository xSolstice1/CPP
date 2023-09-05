#ifndef WEATHER_H
#define WEATHER_H
#include <iostream>
#include <cmath>

using namespace std;

/**
 * @class Weather
 * @brief Header file for Weather Class
 *
 * @author Ang Jin Wei
 * @version 01
 * @date 6/17/2023
 */

class Weather
{
public:

    /**
     * @brief Default Constructor for Weather
     */
    Weather();

    /**
     * @brief Parametized Constructor for Weather
     *
     * @param s - speed
     * @param sr - solar radiation
     * @param t - temperature
     */
    Weather(float s, float sr, float t);

    /**
     * @brief getSpeed function for Weather
     *
     * @return float speed
     */
    float GetSpeed() const;

    /**
     * @brief getTemp function for Weather
     *
     * @return float temp
     */
    float GetTemp() const;

    /**
     * @brief getSR function for Weather
     *
     * @return float solarRadiation
     */
    float GetSR() const;

    /**
     * @brief setSpeed function for Weather
     *
     * @param s = speed
     *
     * @pre s must be a valid float
     * @post speed = s
     */
    void SetSpeed(float s);

    /**
     * @brief setSR function for Weather
     *
     * @param sr = solar radiation
     *
     * @pre sr must be a valid float
     * @post solarRadiation = sr
     */
    void SetSR(float sr);

    /**
     * @brief setTemp function for Weather
     *
     * @param t = temperature
     *
     * @pre t must be a valid float
     * @post temp = t;
     */
    void SetTemp(float t);

protected:

private:
    float m_speed = 0;
    float m_solarRadiation = 0;
    float m_temp = 0;
};


#endif // WEATHER_H
