#include "Weather.h"

int main()
{
    Weather w;

    cout << "Setting sample weather" << endl << endl;

    w.SetSpeed(5);
    w.SetSR(6);
    w.SetTemp(7);

    cout << "Test getters" << endl << endl;

    cout << "Speed: " << w.GetSpeed() << "\nTemp: " << w.GetTemp() << "\nSR: " << w.GetSR() << endl << endl;


    return 0;
}
