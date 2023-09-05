#include "BST.h"
#include "Collector.h"
#include "Value.h"
#include <iostream>

using namespace std;

float Collector::m_max = 0;
float Collector::m_min = 999;
float Collector::m_total = 0;

bool operator>(const Value &L, const Value &R);

int main()
{
    BST<Value> tree;
    Collector c;
    Value v;

    v.SetValue(1);
    tree.InsertItem(v);
    v.SetValue(2);
    tree.InsertItem(v);
    v.SetValue(30);
    tree.InsertItem(v);
    v.SetValue(4);
    tree.InsertItem(v);
    v.SetValue(6);
    tree.InsertItem(v);
    v.SetValue(20);
    tree.InsertItem(v);

    tree.InOrderTraversal(c.Sum);
    cout << "The sum of all values in the tree is: " << c.GetSum() << endl;
    tree.InOrderTraversal(c.Max);
    cout << "The largest value in the tree is: " << c.GetMax() << endl;
    tree.InOrderTraversal(c.Min);
    cout << "The largest value in the tree is: " << c.GetMin() << endl;

}

bool operator>(const Value &L, const Value &R)
{
    float a = L.GetValue();
    float b = R.GetValue();

    return a > b;
}
