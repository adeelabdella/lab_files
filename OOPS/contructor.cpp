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
    Location arr[] = {
        Location(28.66992, 77.29162, "Shahadra mandi, eastern"),
        Location(28.68991, 77.30672, "GTB Brossing, eastern"),
        Location(28.68991, 77.25796, "kalash nagar pusta, eastern"),
        Location(28.64789, 77.29509, "jagatpuri red light, eastern"),
        Location(28.65005, 77.31381, "ISBT Ananad Vihar, eastern"),
        Location(28.67069, 77.26678, "Seelampur T-oint, eastern"),
        Location(28.7111, 77.26034, "khajori chowk, eastern"),
        Location(28.70129, 77.29146, "loni gol chakkar, eastern"),
        Location(28.61812, 77.32086, "kondii Bridge, eastern"),
        Location(28.63583, 77.28713, "nirman vihar, eastern")};

    double totalDist = 0;
    for (int i = 1; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        totalDist += arr[i].distFrom(arr[i - 1]);
    }
    cout << "Total Distance = " << totalDist << endl;
}