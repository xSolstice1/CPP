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
    int GetHour() const;

    /**
     * @brief getMinute function for Time
     *
     * @return int minute
     */
    int GetMinute() const;

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
    void SetHour(int h);

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
    void SetMinute(int m);

protected:

private:
    int m_hour = 0;
    int m_minute = 0;
};


#endif // TIME_H
