#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int DiamondCollector(vector<int>& diamonds, const int k) {
  int max_num_diamond = 0;
  sort(diamonds.begin(), diamonds.end());
  int left = 0;
  int right = 0;
  while (right < diamonds.size()) {
    while (right < diamonds.size() && diamonds[right] - diamonds[left] <= k) {
      right++;
    }
    max_num_diamond = max(max_num_diamond, right - left);
    left++;
  }
  return max_num_diamond;
}

int main() {
  int n, k;
  ifstream fin("diamond.in");
  ofstream fout("diamond.out");
  fin >> n >> k;
  vector<int> diamonds(n);
  for (auto& diamond : diamonds) {
    fin >> diamond;
  }
  fout << DiamondCollector(diamonds, k) << endl;

  fin.close();
  fout.close();
  return 0;
}