#include <bits/stdc++.h>
#include "oops5.h"
using namespace std;

int main()
{

    Point p1(1, 1);
    Point p2(2.6, -2);
    cout << "lNorm P1 = " << p1.l2Norm() << endl;
    cout << "lNorm P2 = " << p2.l2Norm() << endl;
    cout << p2[1] << endl;
    p2[1] = 7;
    p2.printCoords();
    cin >> p2;
    cout << p2 << endl;

    return 0;
}
