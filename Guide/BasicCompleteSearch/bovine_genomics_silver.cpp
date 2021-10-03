#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int CountPotentialSpottyPosition(vector<string>& spotty_cows,
                                 vector<string>& plain_cows, const int n,
                                 const int m) {
  int count = m * (m - 1) * (m - 2) / 6;
  cout << count;
  unordered_set<string> genomes;
  for (int x = 0; x < m; x++) {
    for (int y = x + 1; y < m; y++) {
      for (int z = y + 1; z < m; z++) {
        for (int i = 0; i < n; i++) {
          genomes.insert(string(" ") + spotty_cows[i][x] + spotty_cows[i][y] +
                         spotty_cows[i][z]);
        }

        for (int i = 0; i < n; i++) {
          if (genomes.count(string(" ") + plain_cows[i][x] + plain_cows[i][y] +
                            plain_cows[i][z]) != 0) {
            count--;
            break;
          }
        }

        genomes.clear();
      }
    }
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