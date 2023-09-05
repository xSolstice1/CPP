#include <iostream>
#include <string>
#include "Vector.h"


using namespace std;

int main()
{
    Vector<string> newvector;
    newvector.pushBack("Test");
    newvector.pushBack("Test2");
    newvector.pushBack("Test3");
    newvector.popBack(); //remove last element of vector
    newvector.pushBack("Test4");

    Vector<string> copyvector(newvector);

    newvector = copyvector;

    copyvector.pushBack("test");

    copyvector.printVector();
    copyvector.getCapacity();
    copyvector.pushBack("test");
    copyvector.pushBack("test");
    copyvector.pushBack("test");
    copyvector.pushBack("test");
    copyvector.getCapacity();
    cout << copyvector.Size();




    return 0;
}
