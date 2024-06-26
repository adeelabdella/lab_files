#include <bits/stdc++.h>
using namespace std;
int findblock(set<int> leader, int line) {
  vector<int> vect;
  for (auto it = leader.begin(); it != leader.end(); it++) {
    vect.push_back(*it);
  }
  for (int i = 1; i < vect.size(); i++) {
    if (vect[i - 1] <= line && vect[i] > line) return i;
  }
  return leader.size();
}
int main() {
  ifstream file("../data/lab6_tac.txt", ios::in);
  vector<string> table;
  string line = "";
  set<int> leader;
  leader.insert(1);

  // ***********************************Extract Data***************************
  while (getline(file, line)) {
    string compare = "goto";
    int j = 0;
    for (int i = 0; i <= line.size(); i++) {
      if (line[i] == compare[j])
        j++;
      else
        j = 0;
      if (j == 4) {
        int t = 0;
        i += 2;
        while (line[i] != ')') {
          t = t * 10 + line[i] - '0';
          i++;
        }
        leader.insert(t);
        leader.insert(table.size() + 2);
        break;
      }
    }
    table.push_back(line);
  }
  file.close();
  auto it = leader.begin();
  int i = 0, j = 1, end = *it;
  int n = leader.size();
  vector<vector<int>> mat(n, vector<int>(n, 0));
  while (i < table.size()) {
    int start = end, m = 0;
    it++;
    if (it != leader.end())
      end = *it;
    else
      end = table.size() + 1;
    bool flag = true;
    for (int k = start; k < end; k++) {
      string compare = "goto";
      m = 0;
      for (int p = 0; p < table[k - 1].size(); p++) {
        if (table[k - 1][p] == compare[m])
          m++;
        else
          m = 0;
        if (m == 4) {
          int t = 0;
          p += 2;
          while (table[k - 1][p] != ')') {
            t = t * 10 + table[k - 1][p] - '0';
            p++;
          }
          mat[j - 1][findblock(leader, t) - 1] = 1;
          if (table[k - 1][0] == 'g') {
            flag = false;
          }
          break;
        }
      }

      // cout << setw(10) << left << k << table[k - 1] << endl;
    }
    if (flag) mat[j - 1][j] = 1;

    cout << j << endl;
    j++;
    i = end;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
