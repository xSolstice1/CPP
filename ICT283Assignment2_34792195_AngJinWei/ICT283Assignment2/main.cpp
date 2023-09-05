#include "Menu.h"

using namespace std;

int main()
{
    //create menu object, read data and load menu
    Menu menu;
    menu.ReadData();
    menu.LoadMenu();

    /*test spcc
    vector<double> x;
    vector<double> y;

    x.push_back(9);
    x.push_back(7);
    x.push_back(5);
     x.push_back(3);
      x.push_back(1);
    y.push_back(10);
    y.push_back(6);
    y.push_back(1);
    y.push_back(5);
    y.push_back(3);


    cout << menu.CalculateSPCC(x,y);*/


    return 0;
}
