#ifndef WEATHER_H
#define WEATHER_H
#include <iostream>
#include <cmath>

#include "Vector.h"

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
        float getSpeed() const;

            /**
             * @brief getTemp function for Weather
             *
             * @return float temp
             */
        float getTemp() const;

            /**
             * @brief getSR function for Weather
             *
             * @return float solarRadiation
             */
        float getSR() const;

            /**
             * @brief setSpeed function for Weather
             *
             * @param s = speed
             *
             * @pre s must be a valid float
             * @post speed = s
             */
        void setSpeed(float s);

            /**
             * @brief setSR function for Weather
             *
             * @param sr = solar radiation
             *
             * @pre sr must be a valid float
             * @post solarRadiation = sr
             */
        void setSR(float sr);

            /**
             * @brief setTemp function for Weather
             *
             * @param t = temperature
             *
             * @pre t must be a valid float
             * @post temp = t;
             */
        void setTemp(float t);

    protected:

    private:
        float speed = 0;
        float solarRadiation = 0;
        float temp = 0;
};

    /**
     * @brief ostream output operator
     *
     * @param ostream reference to os
     * @param Weather reference to W
     *
     */
ostream & operator << (ostream & os, const Weather & W);

    /**
     * @brief istream input operator
     *
     * @param istream reference to input
     * @param Weather reference to W
     *
     */
istream & operator >> (istream & input, Weather & W);

#endif // WEATHER_H
