#ifndef VALUE_H
#define VALUE_H
#include <string>

using namespace std;

/**
 * @class Value
 * @brief Header file for Value Class
 *
 * @author Ang Jin Wei
 * @version 01
 * @date 7/24/2023
 */

class Value
{
public:
    /**
    * @brief Destructor for Value
    * @post m_value is set to 0
    */
    ~Value();

    /**
    * @brief Function to get value stored in Value class
    * @post return m_value
    */
    float GetValue() const;

    /**
    * @brief Function to set value store in Value class
    * @param value = the value to set
    * @post m_value is set to value
    */
    void SetValue(float value);

protected:

private:
    float m_value;
};

#endif // VALUE_H
