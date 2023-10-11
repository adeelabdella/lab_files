#include <bits/stdc++.h>
#include "element_inherit_poly.h"
#include "sorting_algo.h"

using namespace std;

typedef void (*SortFunction)(Element *to_sort[], const int N);
double sortingExecutor(Element *to_sort[], const int N, SortFunction sortFunc, bool toPrint = false)
{
    auto start_time = chrono::high_resolution_clock::now();
    sortFunc(to_sort, N);
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    if (toPrint)
    {
        for (int i = 0; i < N; i++)
        {
            to_sort[i]->print();
        }
    }
    return static_cast<double>(duration.count());
}

int main()
{
    const int SIZES[5] = {10, 100, 1000, 10000, 50000};
    for (int i = 0; i < 4; i++)
    {
        const int N = SIZES[i];
        Element *to_sort1[N], *to_sort2[N], *to_sort3[N];
        for (int i = 0; i < N; i++)
        {
            if (i % 3 == 0)
            {
                double x = rand_gen();
                double y = rand_gen();
                to_sort1[i] = new Point(x, y);
                to_sort2[i] = new Point(x, y);
                to_sort3[i] = new Point(x, y);
            }
            else if (i % 3 == 1)
            {
                double x = rand_gen();
                double y = rand_gen();
                double z = rand_gen();
                to_sort1[i] = new Vector(x, y, z);
                to_sort2[i] = new Vector(x, y, z);
                to_sort3[i] = new Vector(x, y, z);
            }
            else
            {
                int dimension = rand() % 8 + 2;
                double *arr = new double[dimension];
                for (int i = 0; i < dimension; i++)
                {
                    arr[i] = rand_gen();
                }
                to_sort1[i] = new PointN(dimension, arr);
                to_sort2[i] = new PointN(dimension, arr);
                to_sort3[i] = new PointN(dimension, arr);
            }
        }
        double time1 = sortingExecutor(to_sort1, SIZES[i], sort_algo_1);
        double time2 = sortingExecutor(to_sort2, SIZES[i], sort_algo_2);
        double time3 = sortingExecutor(to_sort3, SIZES[i], sort_algo_3);

        cout << "Sorting Executor 1 = " << static_cast<long long>(time1) << " \xC2\xB5s"
             << " | ";
        cout << "Sorting Executor 2 = " << static_cast<long long>(time2) << " \xC2\xB5s"
             << " | ";
        cout << "Sorting Executor 3 = " << static_cast<long long>(time3) << " \xC2\xB5s" << endl;

        cout << "Speed Ratio 1/2 = " << time1 / time2 << endl;
        cout << "Speed Ratio 1/3 = " << time1 / time3 << endl;
        cout << "Speed Ratio 2/3 = " << time2 / time3 << endl;
        cout << "Speed Ratio 3/1 = " << time3 / time1 << endl;
        cout << "Speed Ratio 3/2 = " << time3 / time2 << endl;
        cout << "Speed Ratio 2/1 = " << time2 / time1 << endl;
        cout << endl;
    }
    return 0;
}