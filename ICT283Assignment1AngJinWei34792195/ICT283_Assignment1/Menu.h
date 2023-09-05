#ifndef MENU_H
#define MENU_H

#include "WindLog.h"
#include "Vector.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>

	/**
	 * @class Menu
	 * @brief Header file for Menu Class
	 *
	 * @author Ang Jin Wei
	 * @version 01
	 * @date 6/17/2023
	 */

class Menu
{
    public:

            /**
             * @brief Default Constructor for Menu
             */
        Menu();

            /**
             * @brief ReadData function for Menu
             *
             * @pre Data/data_source.txt must have a filename to read from
             * @post Data will be read and pushed into wVector
             */
        void ReadData();

            /**
             * @brief OptionOne function for Menu
             *
             * @pre Data must be read, user must enter a valid month and year
             * @post Avg windspeed and sd for specific month and year will be displayed
             */
        void OptionOne();

            /**
             * @brief OptionTwo function for Menu
             *
             * @pre Data must be read, user must enter a valid year
             * @post Avg temp and sd for each month of the year will be displayed
             */
        void OptionTwo();

            /**
             * @brief OptionThree function for Menu
             *
             * @pre Data must be read, user must enter a valid year
             * @post Total solar radiation in kWh/m^2 for each month of the year will be displayed
             */
        void OptionThree();

            /**
             * @brief OptionFour function for Menu
             *
             * @pre Data must be read, user must enter a valid year
             * @post Data will be output to Data/WindSolarTemp.csv
             */
        void OptionFour();

            /**
             * @brief LoadMenu function for Menu
             *
             * @pre Data must be read
             * @post Menu will be loaded
             */
        void LoadMenu();

    private:
        Vector <WindLog> wVector;
};

#endif // MENU_H
