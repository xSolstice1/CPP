#include "Date.h"

int main()
{
    Date d;

    cout << "Setting sample date" << endl << endl;

    d.SetDay(5);
    d.SetMonth(5);
    d.SetYear(1997);

    cout << "Test getters" << endl << endl;

    cout << "Day: " << d.GetDay() << endl;
    cout << "Month: " << d.GetMonth() << endl;
    cout << "Year: " << d.GetYear() << endl << endl;

    cout << "Test month-to-name" << endl << endl;

    cout << "Month in digit: " << d.GetMonth() << " Month's name: " << d.MonthName(d.GetMonth()) << endl;

    return 0;
}
