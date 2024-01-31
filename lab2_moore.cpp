#include <fstream>
#include <iostream>
#include <vector>

#include "print.h"

using namespace std;

void get_final_state(vector<int>& final_state, string& line) {
  string numstr = "";
  line.push_back(' ');
  for (char ch : line) {
    if (ch == ' ' && numstr.size() > 0) {
      final_state.push_back(stoi(numstr));
      numstr.clear();
    }
    numstr.push_back(ch);
  }
}

vector<pair<int, int>> get_transitions(string& line) {
    
}

int main() {
  ifstream file("../data/lab2_moore.txt", ios::in);
  if (!file.is_open()) {
    cerr << "File opening failed\n";
    return 1;
  }
  string line;
  int i = 0, initial_state = 0;
  vector<int> final_state;
  vector<vector<pair<int, int>>> matrix;
  while (getline(file, line)) {
    std::cout << line << endl;
    if (i == 0) {
      try {
        initial_state = stoi(line);
      } catch (const exception& e) {
        cerr << e.what() << "\nInvalid Initial State";
        return 0;
      }
    } else if (i == 1) {
      try {
        get_final_state(final_state, line);
      } catch (const exception& e) {
        cerr << e.what() << "\nInvalid Final State(s)";
        return 0;
      }
    } else {
      matrix.push_back(get_transitions(line));
    }
    ++i;
  }
  std::cout << "Initial State : ";
  print(initial_state);
  std::cout << "Final State   : ";
  print(final_state);
  file.close();
  return 0;
}