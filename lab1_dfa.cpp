// #include <bits/stdc++.h>
// #include <fstream>

// using namespace std;
// bool isFinalState(vector<int> fs, int cur)
// {
//     int i = 0;
//     for (; i < fs.size(); i++)
//     {
//         if (fs[i] == cur)
//         {
//             return true;
//         }
//     }
//     return false;
// }
// vector<int> lineToVec(string line)
// {

//     int i = 0;
//     vector<int> v;
//     for (; i < line.length(); i++)
//     {
//         if (line[i] == '-')
//         {
//             v.push_back(-1);
//         }
//         else if (line[i] != ',')
//         {
//             v.push_back(line[i] - '0');
//         }
//     }
//     return v;
// }
// bool isAccepted(string str, vector<vector< int > > table, vector<int>
// finalStates, int qi)
// {

//     int len = str.length();
//     int m = table[0].size();
//     int i = 0, cur = 0;
//     while (i < len && cur != -1)
//     {
//         if (str[i] - '0' >= m)
//         {
//             return false;
//         }
//         cur = table[cur][str[i] - '0'];
//         i++;
//     }
//     if (isFinalState(finalStates, cur))
//     {
//         return true;
//     }
//     return false;
// }
// int main()
// {
//     ifstream fin;
//     string l;
//     fin.open("./data/lab1_dfa.txt");
//     int cnt = 0;
//     int qi;
//     vector<int> finalStates;
//     vector<vector< int > > table;
//     while (getline(fin, l))
//     {
//         cnt++;
//         vector<int> temp = lineToVec(l);
//         if (cnt == 1)
//         {
//             qi = temp[0];
//         }
//         else if (cnt == 2)
//         {
//             int i = 0;
//             for (; i < temp.size(); i++)
//             {
//                 finalStates.push_back(temp[i]);
//             }
//         }
//         else
//         {
//             table.push_back(temp);
//         }
//         cout << endl;
//     }
//     fin.close();
//     string s, ans;
//     cout << "Enter string " << endl;
//     getline(cin, s);
//     if (isAccepted(s, table, finalStates, qi))
//     {
//         ans = "Accepted";
//     }
//     else
//     {
//         ans = "not accepted";
//     }
//     cout << "The Input " << s << " is " << ans << endl;
//     return 0;
// }

#include <bits/stdc++.h>

#include <fstream>
using namespace std;

int finalStates(vector<int> &v, int c) {
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == c) return 1;
  }
  return 0;
}

vector<int> stringToVector(string &line) {
  int i = 0;
  vector<int> v;
  while (i < line.size()) {
    if (line[i] == '-') {
      int x = -1;
      v.push_back(x);
      i++;
    } else if (line[i] != '-' && line[i] != ' ') {
      v.push_back(line[i] - '0');
    }
    i++;
  }
  return v;
}

int isAccepted(string &s) {
  fstream file("../data/lab1_dfa.txt", ios::in);
  int n = s.size();
  vector<vector<int>> v;
  string line;

  while (getline(file, line)) {
    vector<int> temp;
    temp = stringToVector(line);
    v.push_back(temp);
  }
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      cout << v[i][j];
    }
    cout << endl;
  }

  vector<int> finalState = v[1];
  int i = 0;
  int currentState = 0;
  int sz = v[2].size();
  int p = v.size();

  while (currentState != -1 && i < n) {
    if (s[i] - 'a' >= sz)
      return 0;
    else {
      currentState = v[currentState + 2][s[i] - 'a'];
      i++;
    }
  }

  if (finalStates(finalState, currentState))
    return 1;
  else
    return 0;
}

int main() {
  string s;
  cout << "Enter the string :";
  cin >> ws;
  getline(cin, s);

  cout << "Input String : " << s << endl;
  if (isAccepted(s))
    cout << "Accepted";
  else
    cout << "Not Accepted";

  return 0;
}