#include <bits/stdc++.h>
#include "element_inherit_poly.h"

using namespace std;

void sort_algo_1(Element *to_sort[], const int N = 10000)
{
    int i, j;
    Element *key = nullptr;
    for (i = 1; i < N; i++)
    {
        key = to_sort[i];
        j = i - 1;
        while (j >= 0 && to_sort[j]->norm() > key->norm())
        {
            to_sort[j + 1] = to_sort[j];
            j -= 1;
        }
        to_sort[j + 1] = key;
    }
}

void sort_algo_2(Element *to_sort[], const int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (to_sort[j]->norm() > to_sort[j + 1]->norm())
            {
                // Swap to_sort[j] and to_sort[j+1]
                Element *temp = to_sort[j];
                to_sort[j] = to_sort[j + 1];
                to_sort[j + 1] = temp;
            }
        }
    }
}

void sort_algo_3(Element *to_sort[], const int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < N; j++)
        {
            if (to_sort[j]->norm() < to_sort[min_index]->norm())
            {
                min_index = j;
            }
        }
        Element *temp = to_sort[i];
        to_sort[i] = to_sort[min_index];
        to_sort[min_index] = temp;
    }
}

// void sort_algo_2(Element *to_sort[], const int N = 10000)
// {
//     for (int i = 1; i < N; i++)
//     {
//         Element *key = to_sort[i];
//         int j = i - 1;
//         bool flag = to_sort[j]->norm() > key->norm();
//         while (j >= 0 && flag)
//         {
//             to_sort[j + 1] = to_sort[j];
//             j--;
//             flag = to_sort[j]->norm() > key->norm();
//         }
//         to_sort[j + 1] = key;
//     }
// }

// void sort_algo_3(Element *to_sort[], const int N = 10000)
// {
//     int i, j;
//     Element *key = nullptr;
//     for (i = 1; i < N; i++)
//     {
//         key = to_sort[i];
//         j = i - 1;
//         while (j >= 0)
//         {
//             if (to_sort[j]->norm() > key->norm())
//             {
//                 to_sort[j + 1] = to_sort[j];
//                 j -= 1;
//             }
//             else
//             {
//                 break;
//             }
//         }
//         to_sort[j + 1] = key;
//     }
// }