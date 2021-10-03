#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int CountCrossingPair(const string& line) {
  int count = 0;
  unordered_set<char> seen_points;
  for (int i = 0; i < line.size(); i++) {
    if (seen_points.count(line[i]) == 0) {
      seen_points.insert(line[i]);
      unordered_map<int, int> mp;
      for (int j = i + 1; j < line.size(); j++) {
        if (line[i] == line[j]) {
          break;
        }
        mp[line[j]]++;
      }
      for (const auto& item : mp) {
        if (item.second != 2) {
          count++;
        }
      }
    }
  }
  return count / 2;
}

int main() {
  ifstream fin("circlecross.in");
  ofstream fout("circlecross.out");
  string line;
  fin >> line;
  fout << CountCrossingPair(line) << endl;
  fin.close();
  fout.close();
  return 0;
}