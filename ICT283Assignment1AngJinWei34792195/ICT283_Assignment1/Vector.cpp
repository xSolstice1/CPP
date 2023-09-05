#include "Vector.h"


using namespace std;

int main()
{
    Vector<string> newvector;
    newvector.pushBack("Test");
    newvector.pushBack("Test2");
    newvector.pushBack("Test3");
    newvector.popBack();//test popBack() function
    cout << "\nTest creation of vector, pushback and popback:\n" << endl;
    newvector.printVector();

    Vector<string> copyvector = Vector<string>(newvector); //test copy constructor

     cout << "\nTest copy constructor:\n" << endl;
    copyvector.pushBack("Test4");
    copyvector.printVector();
    newvector.printVector();

    cout << "\nTest At() function to get index 1:\n" << endl;
    cout << copyvector.At(1); //test At() function
    cout << endl << endl;




    return 0;
}
