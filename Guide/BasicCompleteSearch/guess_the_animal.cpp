#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int MaxNumYes(const vector<vector<string>>& characters) {
  int max_num = 0;
  for (int i = 0; i < characters.size(); i++) {
    for (int j = i + 1; j < characters.size(); j++) {
      int count = 0;
      int p = 0;
      int q = 0;
      while (p < characters[i].size() && q < characters[j].size()) {
        if (characters[i][p] < characters[j][q]) {
          p++;
        } else if (characters[j][q] < characters[i][p]) {
          q++;
        } else {
          p++;
          q++;
          count++;
        }
      }
      max_num = max(max_num, count);
    }
  }
  return max_num + 1;
}

int main() {
  ifstream fin("guess.in");
  ofstream fout("guess.out");
  int n, k;
  string animal_name;
  fin >> n;
  vector<vector<string>> characters(n);
  for (int i = 0; i < n; i++) {
    fin >> animal_name >> k;
    characters[i].resize(k);
    for (auto& character : characters[i]) {
      fin >> character;
    }
    sort(characters[i].begin(), characters[i].end());
  }

  fout << MaxNumYes(characters) << endl;

  fin.close();
  fout.close();
  return 0;
}
