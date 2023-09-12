#include <bits/stdc++.h>
#include "oops5.h"
using namespace std;

void insertionSort(Point arr[], int n)
{
    int i, j;
    Point key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j].l2Norm() > key.l2Norm())
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{

    Point p1(1, 1);
    Point p2(2.6, -2);
    cout << "lNorm P1 = " << p1.l2Norm() << endl;
    cout << "lNorm P2 = " << p2.l2Norm() << endl;
    cout << p2[1] << endl;
    p2[1] = 7;
    p2.printCoords();
    Point arr[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    insertionSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
