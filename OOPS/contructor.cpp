#include <bits/stdc++.h>
#include "points_header.h"
using namespace std;

class Location : public Point
{
    string _address;

public:
    Location();
    Location(double, double, string);
    Location(double, double);
    void getData();
    ~Location();
};

Location::Location(double x, double y, string address) : Point(x, y), _address(address)
{
    cout << "Parametrised Location Constructor\n";
}
Location::Location(double x, double y) : Point(x, y)
{
    cout << "Parametrised Location Constructor\n";
}
Location::Location()
{
    cout << "Default Location Constructor\n";
}
Location::~Location()
{
    cout << "Destructor Location is called for : " << _address << endl;
}
void Location::getData()
{
    cout << "Address : " << _address << endl
         << "Coords : ";
    printCoords();
}

void questionOne();
void questionTwo();
int main()
{
    // questionOne();
    questionTwo();
    return 0;
}

void questionOne()
{
    Location loc(4, 65, "HelloDogg");
    Location locDefault;
    loc.getData();
    Location locWithCoords(1.25, 56);
    locWithCoords.getData();
    locDefault.getData();
}

void questionTwo()
{
    Location loc1(1.2, 2.5, "loc1");
    Location loc2(1.2, 7.9, "loc2");
    double dist = loc1.distFrom(loc2);
    cout << dist << endl;
}