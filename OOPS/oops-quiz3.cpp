#include <bits/stdc++.h>
#include "oops5.h"
using namespace std;

class MyClass
{
    int value;

public:
    MyClass() : value(0)
    {
        cout << "Default constructor" << endl;
    }
    MyClass(int val) : value(val)
    {
        cout << "Copy constructor" << endl;
    }
    int getValue()
    {
        return value;
    }
    operator int() const
    {
        return value;
    }
    // conversion function must be a nonstatic member function
    // friend operator MyClass(int x)
    // {
    //     return MyClass(x);
    // }
};

int main()
{
    MyClass obj;
    obj = 5;
    cout << static_cast<char>(toupper('a')) << endl;
    cout << obj.getValue() << endl;
    return 0;
}