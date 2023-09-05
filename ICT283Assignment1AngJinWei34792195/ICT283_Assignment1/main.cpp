#include "Menu.h"

using namespace std;

int main()
{
    //create menu object, read data and load menu
    Menu menu;
    menu.ReadData();
    menu.LoadMenu();

    return 0;
}
