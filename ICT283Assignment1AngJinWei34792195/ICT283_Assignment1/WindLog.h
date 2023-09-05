#ifndef WINDLOG_H
#define WINDLOG_H

#include <iostream>
#include "Date.h"
#include "Time.h"
#include "Weather.h"
#include "Vector.h"

	/**
	 * @class WindLog
	 * @brief Header file for WindLog Class
	 *
	 * @author Ang Jin Wei
	 * @version 01
	 * @date 6/17/2023
	 */


class WindLog
{
    public:

            /**
             * @brief Default Constructor for WindLog
             */
        WindLog();

            /**
             * @brief Parametized Constructor for WindLog
             *
             * @param d - Date object
             * @param t - Time object
             * @param w - Weather object
             */
        WindLog(Date d, Time t, Weather w);

            /**
             * @brief setDate function
             *
             * @param d - Date object
             *
             * @pre Date object must be initialized
             * @post Date will be set to d
             */
        void setDate(Date d);

            /**
             * @brief setTime function
             *
             * @param t - Time object
             *
             * @pre Time object must be initialized
             * @post Time will be set to t
             */
        void setTime(Time t);

            /**
             * @brief setWeather function
             *
             * @param w - Weather object
             *
             * @pre Weather object must be initialized
             * @post Weather will be set to w
             */
        void setWeather(Weather w);

            /**
             * @brief getDate function
             *
             * @return Date
             */
        Date getDate() const;

            /**
             * @brief getTime function
             *
             * @return Time
             */
        Time getTime() const;

            /**
             * @brief getWeather function
             *
             * @return Weather
             */
        Weather getWeather() const;


    private:
        Date date;
        Time time;
        Weather weather;

};


    /**
     * @brief ostream output operator
     *
     * @param ostream reference to os
     * @param WindLog reference to W
     *
     */
ostream& operator << (ostream& os, const WindLog& W);

    /**
     * @brief istream input operator
     *
     * @param input reference to input
     * @param WindLog reference to W
     *
     */
istream& operator >> (istream& input, WindLog& W);


#endif // WINDLOG_H
