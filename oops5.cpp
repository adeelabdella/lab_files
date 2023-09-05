#include <iostream>
#include <math.h>

#define TOLERANCE 0.5

using namespace std;

class Point
{
    static int count;
    double _x;
    double _y;

public:
    void setCoords(double x, double y);
    void printCoords();
    double distFrom(Point &p) const;
    Point midPoint(Point &p);
    Point();                               // This is the DEFAULT constructor
    Point(double x, double y);             // This is the PARAMETERIZED constructor
    Point(Point &p);                       // This is the COPY constructor
    ~Point();                              // This is the destructor
    static int objInstances();             // static memeber function
    Point operator+(const Point &p) const; // Ans 1 -> Operator overload declaration, Ans 2 -> Return type 'Point' and Argument Type 'Point'.
    bool operator<(const Point &p) const;
    bool operator>(const Point &p) const;
    bool operator==(const Point &p) const;
    static int getCount();
};

Point ::Point()
{
    count++;
    _x = _y = 0;
    cout << "constructor is called" << endl;
}

Point ::~Point()
{
    count--;
    cout << "Destructor is called for " << _x << "," << _y << endl;
} // destructor

Point ::Point(double x, double y)
{
    count++;
    _x = x;
    _y = y;

    cout << "Parameterized constructor is called" << endl;
} // Parameterized constructor

// memeber functions
void Point ::setCoords(double x, double y)
{
    _x = x;
    _y = y;
}

void Point ::printCoords()
{
    cout << _x << "," << _y << endl;
}

// 5. Memeber function accessing private member of all objects of this class.

double Point ::distFrom(Point &p) const
{
    // const memeber because it can't change the data memeber of this object
    double d;
    d = sqrt(pow((_x - p._x), 2) + pow((_y - p._y), 2));
    return d;
}

Point Point ::midPoint(Point &p)
{

    Point nP;

    nP._x = (_x + p._x) / 2;
    nP._y = (_y + p._y) / 2;

    return nP;
}

int Point ::count = 0; // definition of static variable. Memory is allocated here;

int Point ::objInstances()
{
    return count;
}

// Ans 4
Point Point ::operator+(const Point &p) const
{
    Point p3;
    p3._x = _x + p._x;
    p3._y = _y + p._y;
    return p3;
}

// Problem 2
bool Point ::operator<(const Point &p) const
{
    double d1 = _x * _x + _y * _y;
    double d2 = p._x * p._x + p._y * p._y;
    return d1 < d2;
}

bool Point ::operator>(const Point &p) const
{
    double d1 = _x * _x + _y * _y;
    double d2 = p._x * p._x + p._y * p._y;
    return d1 > d2;
}

bool Point ::operator==(const Point &p) const
{
    double d1 = _x * _x + _y * _y;
    double d2 = p._x * p._x + p._y * p._y;
    return fabs(sqrt(d1) - sqrt(d2)) <= TOLERANCE;
}

int main()
{

    Point p1(1, 1);
    Point p2(2.6, -2);
    Point p3(3, 37);
    Point p4;

    p4 = p1 + p2 + p3;

    p4.printCoords();

    if (p1 < p2)
    {
        cout << "P1 is less" << endl;
    }
    else
    {
        cout << "P1 is greater" << endl;
    }

    if (p1 == p2)
    {
        cout << "P1 is equal to p2";
    }
    else
    {
        cout << "not equal";
    }

    return 0;
}
