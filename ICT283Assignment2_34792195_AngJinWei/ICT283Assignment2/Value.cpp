#include "Value.h"

using namespace std;

Value::~Value()
{
    m_value = 0;
}

float Value::GetValue() const
{
    return m_value;
}

void Value::SetValue(float value)
{
    m_value = value;
}
