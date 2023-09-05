#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <string>

using namespace std;


	/**
	 * @class Time
	 * @brief  Header file for Time class
	 *
	 * @author Ang Jin Wei
	 * @version 01
	 * @date 6/17/2023
	 */


class Time
{
    public:

            /**
             * @brief  Default constructor for Time
             */
        Time();

            /**
             * @brief  Parametized constructor for Time
             *
             * @param h - hours
             * @param m - minutes
             */
        Time(int h, int m);

            /**
             * @brief getHour function for Time
             *
             * @return int hour
             */
        int getHour() const;

            /**
             * @brief getMinute function for Time
             *
             * @return int minute
             */
        int getMinute() const;

            /**
             * @brief setHour function for Time
             *
             * @param h - hours
             *
             * @pre h must be a valid int
             * @post hour = h
             *
             * @return void
             */
        void setHour(int h);

            /**
             * @brief setMinute function for Time
             *
             * @param m - minutes
             *
             * @pre m must be a valid int
             * @post minute = m
             *
             * @return void
             */
        void setMinute(int m);

    protected:

    private:
        int hour;
        int minute;
};

    /**
     * @brief ostream output operator
     *
     * @param ostream reference to os
     * @param Time reference to T
     *
     */
ostream & operator << (ostream & os, Time & T);

    /**
     * @brief istream input operator
     *
     * @param istream reference to input
     * @param Time reference to T
     *
     */
istream & operator >> (istream & input, Time & T);


#endif // TIME_H
