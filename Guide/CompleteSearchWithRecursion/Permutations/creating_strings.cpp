#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void CreatingStrings(const string& str, map<char, int>& count,
                     vector<char>& path, vector<vector<char>>& results,
                     int& total) {
  if (path.size() == str.size()) {
    results.push_back(path);
    total++;
  }
  for (auto& [ch, times] : count) {
    if (times != 0) {
      times--;
      path.push_back(ch);
      CreatingStrings(str, count, path, results, total);
      path.pop_back();
      times++;
    }
  }
}

int main() {
  string str;
  cin >> str;
  map<char, int> count;
  for (auto ch : str) {
    count[ch]++;
  }
  vector<char> path;
  vector<vector<char>> results;
  int total = 0;
  CreatingStrings(str, count, path, results, total);
  cout << total << endl;
  for (auto result : results) {
    for (auto ch : result) {
      cout << ch;
    }
    cout << endl;
  }
  return 0;
}