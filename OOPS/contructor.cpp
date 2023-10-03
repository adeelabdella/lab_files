#include <bits/stdc++.h>
#include "location.h"
using namespace std;

void questionOnePartOne();
void questionOnePartTwo();
void questionTwo();
int main()
{
    // questionOnePartOne();
    // questionOnePartTwo();
    questionTwo();
    return 0;
}

void questionOnePartOne()
{
    Location loc(4, 65, "HelloDogg");
    Location locDefault;
    loc.getData();
    Location locWithCoords(1.25, 56);
    locWithCoords.getData();
    locDefault.getData();
}

// void questionOnePartTwo()
// {
//     // distFrom mofdified
//     Location loc1(1.2, 2.5, "loc1");
//     Location loc2(1.2, 7.9, "loc2");
//     double dist = loc1.distFrom(loc2);
//     cout << dist << endl;
// }

void questionTwo()
{
    Location loc1(1.2, 2.5, "loc1");
    Location loc2(1.2, 7.9, "loc2");
    cout << loc1.distFrom(loc2) << endl;
}