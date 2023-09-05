#include "WindLog.h"
#include <iostream>

using namespace std;

int main()
{
    WindLog w;

    cout << "Creating sample Weather,Time,Date" << endl << endl;

    Weather weather = Weather(5,6,7);
    Time time = Time(8,9);
    Date date = Date(10,10,1997);

    cout << "Setting objects in WindLog" << endl << endl;

    w.SetDate(date);
    w.SetTime(time);
    w.SetWeather(weather);

    cout << "Test getters for WindLog" << endl << endl;

    cout << "Date: " << w.GetDate().GetDay() << "/" << w.GetDate().GetMonth() << "/" << w.GetDate().GetYear() << endl;
    cout << "Time: " << w.GetTime().GetHour() << ":" << w.GetTime().GetMinute() << endl;
    cout << "Temp: " << w.GetWeather().GetTemp() << "\nSpeed: " << w.GetWeather().GetSpeed() << "\nSR: " << w.GetWeather().GetSR() << endl;
    return 0;
}
