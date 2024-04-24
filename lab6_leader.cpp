#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream file("../data/lab6_tac.txt", ios::in);
  vector<string> table;
  string line = "";
  set<int> leader;
  leader.insert(1);

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

  // ****************************Printing Block**************************

  cout << "Leader statements are:" << endl;
  cout << setw(10) << left << "Line No"
       << "Statments" << endl;
  for (auto it = leader.begin(); it != leader.end(); it++) {
    cout << setw(10) << left << *it;
    cout << table[*it - 1] << endl;
  }
  cout << "Block statements are:" << endl;
  auto it = leader.begin();
  int i = 0, j = 1, end = *it;
  while (i < table.size()) {
    int start = end;
    it++;
    if (it != leader.end())
      end = *it;
    else
      end = table.size() + 1;
    cout << setw(8) << left << "Block " << j << endl;
    cout << setw(10) << left << "Line No"
         << "Statments" << endl;
    for (int k = start; k < end; k++) {
      cout << setw(10) << left << k << table[k - 1] << endl;
    }
    j++;
    i = end;
  }
  return 0;
}
