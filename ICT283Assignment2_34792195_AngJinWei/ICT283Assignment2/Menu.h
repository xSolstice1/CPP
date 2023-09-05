#ifndef MENU_H
#define MENU_H

#include "WindLog.h"
#include "BST.h"
#include "Collector.h"
#include "Value.h"
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

/**
 * @class Menu
 * @brief Header file for Menu Class
 *
 * @author Ang Jin Wei
 * @version 02
 * @date 7/24/2023
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
     * @post Data will be read and pushed into mapObject
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

    /**
    * @brief Function to calculate sPCC
    * @param x,y = vector of float
    * @post spcc will be returned
    */
    double CalculateSPCC(const vector<double> &X, const vector<double> &Y);

    /**
    * @brief Function to calculate average speed
    * @param m = map, month = month to calculate, year = year to calculate
    * @post Average speed will be returned
    */
    float CalculateAverageSpeed(map<int,map<int,vector<WindLog>>> &m, int month, int year);

    /**
    * @brief Function to calculate average temperature
    * @param m= map, month = month to calculate, year = year to calculate
    * @post Average temperature will be returned
    */
    float CalculateAverageTemp(map<int,map<int,vector<WindLog>>> &m, int month, int year);

    /**
    * @brief Function to calculate stdev of speed
    * @param m = map, month = month to calculate, year = year to calculate, avg = average of the sample data
    * @post Speed stdev will be returned
    */
    float CalculateSpeedSD(map<int,map<int,vector<WindLog>>> &m, int month, int year, float avg);

    /**
    * @brief Function to calculate stdev of temperature
    * @param m = map, month = month to calculate, year = year to calculate, avg = average of the sample data
    * @post Temperature stdev will be returned
    */
    float CalculateTempSD(map<int,map<int,vector<WindLog>>> &m, int month, int year, float avg);

    /**
    * @brief Function to get user input on year
    * @post User specified year as int will be returned
    */
    int InputYear();

    /**
    * @brief Function to get user input on month
    * @post User specified month as int will be returned
    */
    int InputMonth();

private:
    map<int,map<int,vector<WindLog>>> mapObject;
    int MAX_YEAR = 0;
    int MIN_YEAR = 0;
};

#endif // MENU_H
