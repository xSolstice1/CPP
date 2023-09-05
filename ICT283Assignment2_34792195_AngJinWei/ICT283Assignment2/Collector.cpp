#include "Collector.h"

using namespace std;

Collector::~Collector()
{
    m_total = 0;
    m_max = 0;
    m_min = 0;
}

void Collector::Max(Value &value)
{
    if (value.GetValue() > m_max)
    {
        m_max = value.GetValue();
    }
}

void Collector::Min(Value &value)
{
    if (value.GetValue() < m_min)
    {
        m_min = value.GetValue();
    }
}

void Collector::Sum(Value &value)
{
    m_total+=value.GetValue();
}

float Collector::GetSum() const
{
    return m_total;
}

float Collector::GetMax() const
{
    return m_max;
}

float Collector::GetMin() const
{
    return m_min;
}
