#include <bits/stdc++.h>
#include "points_header.h"
using namespace std;

class Location : public Point
{
    string _address;
    static double PI;
    static double RADIUS_OF_EARTH;

public:
    Location();
    Location(double, double, string);
    Location(double, double);
    // const Location& giving error check it
    double distFrom(Location &);
    void getData();
    ~Location();
};

double Location::PI = 2 * asin(1);
double Location::RADIUS_OF_EARTH = 6371;

double Location::distFrom(Location &loc)
{
    pair<double, double> cordThis = getCords();
    pair<double, double> cordThat = loc.getCords();
    cout << cordThis.first << ", " << cordThis.second << endl;
    cout << cordThat.first << ", " << cordThat.second << endl;
    double mThis = cordThis.second / cordThis.first;
    double mThat = cordThat.second / cordThat.first;
    double angle = (mThis - mThat) / (1 + mThat * mThis);
    angle = atan(angle);
    double distance = fabs(angle) * PI * RADIUS_OF_EARTH;
    return distance;
}

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