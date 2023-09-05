#include "Time.h"

int main()
{
    Time t;

    cout << "Setting sample time" << endl << endl;

    t.SetHour(5);
    t.SetMinute(10);

    cout << "Testing getters: " << endl << endl;

    cout << "The time is: " << t.GetHour() << ":" << t.GetMinute() << endl;

    return 0;
}
