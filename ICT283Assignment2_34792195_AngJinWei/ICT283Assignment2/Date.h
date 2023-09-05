#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>

using namespace std;

/**
 * @class Date
 * @brief Header file for Date Class
 *
 * @author Ang Jin Wei
 * @version 01
 * @date 6/17/2023
 */

class Date
{
public:

    /**
     * @brief Default Constructor for Date
     */
    Date();

    /**
     * @brief Parametized Constructor for Date
     *
     * @param d - m_day
     * @param m - m_month
     * @param y - m_year
     */
    Date(int d, int m, int y);

    /**
     * @brief GetDay function for Date
     *
     * @return int m_day
     */
    int GetDay() const;

    /**
     * @brief GetMonth function for Date
     *
     * @return int m_month
     */
    int GetMonth() const;

    /**
     * @brief GetYear function for Date
     *
     * @return int m_year
     */
    int GetYear() const;

    /**
     * @brief SetDay function for Date
     *
     * @param d - m_day
     *
     * @pre d must be a valid int
     * @post m_day = d
     *
     * @return void
     */
    void SetDay(int d);

    /**
     * @brief SetMonth function for Date
     *
     * @param m - m_month
     *
     * @pre m must be a valid int
     * @post m_month = m
     *
     * @return void
     */
    void SetMonth(int m);

    /**
     * @brief SetYear function for Date
     *
     * @param y - m_year
     *
     * @pre y must be a valid int
     * @post m_year = y
     *
     * @return void
     */
    void SetYear(int y);

    /**
    * @brief MonthName function for Date
    *
    * @param m - m_month
    * @return string of month name in alphabet (i.e. monthName(1) - January)
    */
    string MonthName(int m) const;

    bool operator > (const Date &date) const;

protected:

private:
    int m_day = 0;
    int m_month = 0;
    int m_year = 0;
};

#endif // DATE_H
