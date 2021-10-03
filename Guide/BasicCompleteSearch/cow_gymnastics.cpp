#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int CountConsistentPairs(const vector<vector<int>>& ranks, const int n,
                         const int k) {
  int count = n * (n - 1) / 2;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int drank_0 = (ranks[0][i] - ranks[0][j] < 0 ? 0 : 1);
      for (int m = 1; m < k; m++) {
        int drank_m = (ranks[m][i] - ranks[m][j] < 0 ? 0 : 1);
        if ((drank_0 ^ drank_m) != 0x00) {
          count--;
          break;
        }
      }
    }
  }
  return count;
}

int main() {
  int n, k;
  ifstream fin("gymnastics.in");
  ofstream fout("gymnastics.out");
  fin >> k >> n;
  vector<vector<int>> ranks(k, vector<int>(n + 1));
  int temp;
  for (int i = 0; i < k; i++) {
    for (int j = 1; j <= n; j++) {
      fin >> temp;
      ranks[i][temp] = j;
    }
  }
  fout << CountConsistentPairs(ranks, n, k) << endl;
  fin.close();
  fout.close();
}