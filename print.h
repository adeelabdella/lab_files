#include <bits/stdc++.h>
using namespace std;

void print(int& x) { cout << x << endl; }

void print(vector<int>& v) {
  for (auto x : v) {
    cout << x << "\t";
  }
  cout << endl;
}

void print(vector<vector<int>>& v) {
  for (auto x : v) {
    for (auto y : x) {
      cout << y << "\t";
    }
    cout << endl;
  }
}