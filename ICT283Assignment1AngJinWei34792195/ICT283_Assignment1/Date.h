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
             * @param d - day
             * @param m - month
             * @param y - year
             */
        Date(int d, int m, int y);

            /**
             * @brief getDay function for Date
             *
             * @return int day
             */
        int getDay() const;

            /**
             * @brief getMonth function for Date
             *
             * @return int month
             */
        int getMonth() const;

            /**
             * @brief getYear function for Date
             *
             * @return int year
             */
        int getYear() const;

            /**
             * @brief setDay function for Date
             *
             * @param d - day
             *
             * @pre d must be a valid int
             * @post day = d
             *
             * @return void
             */
        void setDay(int d);

            /**
             * @brief setMonth function for Date
             *
             * @param m - month
             *
             * @pre m must be a valid int
             * @post month = m
             *
             * @return void
             */
        void setMonth(int m);

            /**
             * @brief setYear function for Date
             *
             * @param y - year
             *
             * @pre y must be a valid int
             * @post year = y
             *
             * @return void
             */
        void setYear(int y);

            /**
            * @brief monthName function for Date
            *
            * @param m - month
            * @return string of month name in alphabet (i.e. monthName(1) - January)
            */
        string monthName(int m);

    protected:

    private:
        int day;
        int month;
        int year;
};

    /**
     * @brief ostream output operator
     *
     * @param ostream reference to os
     * @param Date reference to D
     *
     */
ostream & operator << (ostream & os, Date & D);

    /**
     * @brief istream input operator
     *
     * @param istream reference to input
     * @param Date reference to D
     *
     */
istream & operator >> (istream & input, Date & D);


#endif // DATE_H
