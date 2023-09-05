#ifndef COLLECTOR_H
#define COLLECTOR_H
#include "Value.h"

using namespace std;

/**
 * @class Collector
 * @brief Header file for Collector Class
 *
 * @author Ang Jin Wei
 * @version 01
 * @date 6/17/2023
 */

class Collector
{
public:
    /**
    * @brief Destructor for Collector
    * @post m_total, m_max, m_min is set to 0
    */
    ~Collector();

    /**
    * @brief Function to get max value
    * @param value = value to compare
    * @post m_max is set to max value
    */
    static void Max(Value &value);

    /**
    * @brief Function to get min value
    * @param value = value to compare
    * @post m_min is set to min value
    */
    static void Min(Value &value);

    /**
    * @brief Function to add values
    * @param value = value to add
    * @post m_total = m_total + value
    */
    static void Sum(Value &value);

    /**
    * @brief Function to get sum
    * @post m_total is returned
    */
    float GetSum() const;

    /**
    * @brief Function to get max
    * @post m_max is returned
    */
    float GetMax() const;

    /**
    * @brief Function to get min
    * @post m_min is returned
    */
    float GetMin() const;

private:
    static float m_total;
    static float m_max;
    static float m_min;
};

#endif // COLLECTOR_H
