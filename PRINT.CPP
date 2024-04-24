#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void print(int &x) { std::cout << std::setw(5) << x << std::endl; }

void print(vector<int> &v) {
  for (auto x : v) {
    std::cout << std::setw(5) << x;
  }
  std::cout << std::setw(5) << std::endl;
}
void print(vector<string> &v) {
  for (auto x : v) {
    std::cout << std::setw(10) << x;
  }
  std::cout << std::endl;
}

void print(vector<vector<int>> &v) {
  for (auto x : v) {
    for (auto y : x) {
      std::cout << std::setw(5) << y;
    }
    std::cout << std::setw(5) << std::endl;
  }
}

void print(vector<vector<string>> &v) {
  for (auto x : v) {
    for (auto y : x) {
      std::cout << std::setw(10) << y;
    }
    std::cout << std::setw(10) << std::endl;
  }
}

void print(vector<vector<pair<int, int>>> &v) {
  for (auto x : v) {
    for (auto y : x) {
      std::cout << std::setw(5) << "(" << y.first << ", " << y.second << ")";
    }
    std::cout << std::setw(5) << std::endl;
  }
}

void print(vector<vector<int>> &v1, vector<int> &v2) {
  for (int i = 0; i < v1.size(); i++) {
    for (auto y : v1[i]) {
      std::cout << std::setw(5) << y;
    }
    std::cout << std::setw(5) << " => " << char(v2[i]);
    std::cout << std::setw(5) << std::endl;
  }
}

void print(map<string, vector<string>> matrix) {
  for (auto x : matrix) {
    std::cout << std::setw(10) << x.first << " => ";
    for (auto y : x.second) {
      std::cout << std::setw(10) << y;
    }
    std::cout << std::endl;
  }
}

void print(unordered_map<string, vector<string>> matrix) {
  for (auto x : matrix) {
    std::cout << std::setw(10) << x.first << " => {";
    for (auto y : x.second) {
      std::cout << y << " ";
    }

    std::cout << "}" << std::endl;
  }
}

void print(vector<pair<string, vector<string>>> matrix) {
  auto remove_chars = [](string &str, char ch) {
    str.erase(std::remove(str.begin(), str.end(), ch), str.end());
    return str;
  };
  for (const auto &row : matrix) {
    string first = row.first;
    // std::cout << std::setw(10) << first + " => ";
    std::cout << std::setw(10) << remove_chars(first, '.') + " => ";
    for (size_t i = 0; i < row.second.size(); ++i) {
      string secondTemp = row.second[i];
      // std::cout << std::setw(10) << row.second[i];
      std::cout << std::setw(10) << remove_chars(secondTemp, ',');
    }
    std::cout << std::endl;
  }
}

void print(std::set<std::string> list) {
  for (auto it : list) {
    std::cout << it << "   ";
  }
  std::cout << std::endl;
}