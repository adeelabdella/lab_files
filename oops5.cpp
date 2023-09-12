#include <bits/stdc++.h>
#include <chrono>
#include "oops5.h"
using namespace std;
#define PRIME 1000000007

void insertionSort(vector<Point> &arr, int n)
{
    int i, j;
    Point key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        // while (j >= 0 && arr[j].l2Norm() > key.l2Norm())
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{

    // Point p1(1, 1);
    // Point p2(2.6, -2);
    // cout << "lNorm P1 = " << p1.l2Norm() << endl;
    // cout << "lNorm P2 = " << p2.l2Norm() << endl;
    // cout << p2[1] << endl;
    // p2[1] = 7;
    // p2.printCoords();
    int arraySize[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 5000, 10000, 50000};
    for (int i = 0; i < sizeof(arraySize) / sizeof(arraySize[0]); i++)
    {
        int size = arraySize[i];
        vector<Point> v(size);
        for (int i = 0; i < size; i++)
        {
            v[i].setCoords(rand() % PRIME, rand() % PRIME);
        }
        cout << "Array Size = " << size << endl;
        auto start_time = chrono::high_resolution_clock::now();
        insertionSort(v, size);
        auto end_time = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
        cout << "Time = " << duration.count() << " \xC2\xB5s" << endl;
        for (int i = 0; i < v.size() && v.size() == 10; i++)
        {
            cout << v[i] << endl;
        }
    }
    // Point arr[5];
    // for (int i = 0; i < 5; i++)
    // {
    //     cin >> arr[i];
    // }

    // insertionSort(arr, 5);
    // for (int i = 0; i < vPoints[0].size(); i++)
    // {
    //     cout << vPoints[0][i] << endl;
    // }

    return 0;
}