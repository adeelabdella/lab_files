#include <bits/stdc++.h>
using namespace std;

const char EPSILON = '@';

void make_first(char s, vector<vector<char>> matrix, map<char, set<char>> &mp);
void make_follow(char s, vector<vector<char>> matrix,
                 map<char, set<char>> first, map<char, set<char>> &mp);
void print_result(std::map<char, std::set<char>> &first_map,
                  std::map<char, std::set<char>> &follow_map);

int main() {
  ifstream file("../data/lab5_first_follow.txt", ios::in);
  string line;
  vector<vector<char>> matrix;
  if (!file.is_open()) {
    cerr << "File opening failed\n";
    return 1;
  }
  while (getline(file, line)) {
    vector<char> temp2;
    cout << line << endl;
    for (int i = 0; i < line.size(); i++) {
      if (line[i] != ' ') temp2.push_back(line[i]);
    }
    matrix.push_back(temp2);
  }
  file.close();
  map<char, set<char>> first_map;
  map<char, set<char>> follow_map;
  follow_map['S'].insert('$');
  for (int i = 0; i < matrix.size(); i++) {
    make_first(matrix[i][0], matrix, first_map);
  }
  for (int i = 0; i < matrix.size(); i++) {
    make_follow(matrix[i][0], matrix, first_map, follow_map);
  }
  cout << "Given matrix: " << endl;
  for (int i = 0; i < matrix.size(); i++) {
    cout << matrix[i][0] << " -> ";
    for (int j = 1; j < matrix[i].size(); j++) {
      cout << matrix[i][j];
    }
    cout << endl;
  }
  cout << endl;
  cout << EPSILON << " -> epsilon" << endl << endl;
  print_result(first_map, follow_map);
  return 0;
}
void make_first(char s, vector<vector<char>> matrix,
                map<char, set<char>> &first_map) {
  int j = 1;
  for (int i = 0; i < matrix.size(); i++) {
    if (matrix[i][0] == s) {
      for (int k = 1; k < matrix[i].size(); k++) {
        if (matrix[i][k] == s) {
          break;
        }
        bool flag = false;
        make_first(matrix[i][k], matrix, first_map);
        for (auto it : first_map[matrix[i][k]]) {
          if (it != EPSILON) {
            first_map[s].insert(it);
          } else if (k == matrix[i].size() - 1) {
            first_map[s].insert(EPSILON);
          } else {
            flag = true;
            continue;
          }
        }
        if (!flag) {
          break;
        }
      }
    }
  }
  if (!(s <= 'Z' && s >= 'A')) {
    first_map[s].insert(s);
  }
}

void make_follow(char s, vector<vector<char>> matrix,
                 map<char, set<char>> first, map<char, set<char>> &follow_map) {
  int j = 1;
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 1; j < matrix[i].size(); j++) {
      if (matrix[i][j] == s) {
        for (int k = j + 1; k <= matrix[i].size(); k++) {
          bool flag = false;
          if (k < matrix[i].size()) {
            if (matrix[i][k] <= 'Z' && matrix[i][k] >= 'A') {
              for (auto it : first[matrix[i][k]]) {
                if (it != EPSILON) {
                  follow_map[s].insert(it);
                } else
                  flag = true;
              }
            } else {
              follow_map[s].insert(matrix[i][k]);
              break;
            }
          } else {
            if (matrix[i][0] == s) break;
            make_follow(matrix[i][0], matrix, first, follow_map);
            for (auto it = follow_map[matrix[i][0]].begin();
                 it != follow_map[matrix[i][0]].end(); it++) {
              follow_map[s].insert(*it);
            }
          }
          if (!flag) break;
        }
      }
    }
  }
}

void print_result(std::map<char, std::set<char>> &first_map,
                  std::map<char, std::set<char>> &follow_map) {
  for (auto it = first_map.begin(); it != first_map.end(); it++) {
    if (it->first == 'S') {
      cout << "First ( " << it->first << " ) = ";
      for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
        cout << *it2 << " ";
      }
      cout << endl;
    }
  }
  for (auto it = first_map.begin(); it != first_map.end(); it++) {
    if (!(it->first <= 'Z' && it->first >= 'A') || it->first == 'S') continue;
    cout << "First ( " << it->first << " ) = ";
    for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
      cout << *it2 << " ";
    }
    cout << endl;
  }
  cout << endl;
  for (auto it = follow_map.begin(); it != follow_map.end(); it++) {
    if (it->first == 'S') {
      cout << "Follow ( " << it->first << " ) = ";
      for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
        cout << *it2 << " ";
      }
      cout << endl;
    }
  }
  for (auto it = follow_map.begin(); it != follow_map.end(); it++) {
    if (!(it->first <= 'Z' && it->first >= 'A') || it->first == 'S') continue;
    cout << "Follow ( " << it->first << " ) = ";
    for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
      cout << *it2 << " ";
    }
    cout << endl;
  }
}