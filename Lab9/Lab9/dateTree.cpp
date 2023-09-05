#include <iostream>
#include <fstream>
#include <sstream>
#include "BST.h"
#include "Date.h"

using namespace std;

int main()
{
    BST<Date> dateTree;
    Date date;

    ifstream infile("Data/MetData_Mar01-2014-Mar01-2015-ALL.csv");
    if (!infile)
    {
        cout << "Error opening file!";
        return -1;
    }
    else
    {
        string str;
        getline(infile,str); //Skip header column
        while (!infile.eof())
        {
            if (infile.peek() == '\n' || infile.eof())
            {
                getline(infile,str,'\n');
                continue;
            }
            else
            {
                infile >> date;
                dateTree.InsertItem(date);
                getline(infile,str,'\n'); //Skip till next line
            }
        }
    }
    infile.close();

    cout << "Inorder Traversal: " << endl;
    dateTree.InOrderTraversal();

    cout << "\nPreorder Traversal: " << endl;
    dateTree.PreOrderTraversal();

    cout << "\nPostorder Traversal: " << endl;
    dateTree.PostOrderTraversal();

    cout << "\nThe height of the tree is: " << dateTree.TreeHeight() << endl;

    return 0;
}
