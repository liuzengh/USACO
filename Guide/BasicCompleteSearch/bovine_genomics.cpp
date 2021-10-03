#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int CountPotentialSpottyPosition(vector<string>& spotty_cows,
                                 vector<string>& plain_cows, const int n,
                                 const int m) {
  int count = m;
  unordered_set<char> genomes;
  for (int pos = 0; pos < m; pos++) {
    for (int i = 0; i < n; i++) {
      genomes.insert(spotty_cows[i][pos]);
    }
    for (int i = 0; i < n; i++) {
      if (genomes.count(plain_cows[i][pos]) != 0) {
        count--;
        break;
      }
    }
    genomes.clear();
  }
  return count;
}

int main() {
  ifstream fin("cownomics.in");
  ofstream fout("cownomics.out");
  int n, m;
  fin >> n >> m;
  vector<string> spotty_cows(n);
  vector<string> plain_cows(n);
  for (auto& cow : spotty_cows) {
    fin >> cow;
  }
  for (auto& cow : plain_cows) {
    fin >> cow;
  }
  fout << CountPotentialSpottyPosition(spotty_cows, plain_cows, n, m) << endl;
  return 0;
}