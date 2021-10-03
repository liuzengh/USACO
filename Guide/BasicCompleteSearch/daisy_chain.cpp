#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int CountAverageFlower(const vector<int>& petals) {
  vector<int> prefix_sum(petals.size() + 1);
  prefix_sum[0] = 0;
  for (int i = 0; i < petals.size(); i++) {
    prefix_sum[i + 1] += prefix_sum[i] + petals[i];
  }
  int count = petals.size();
  for (int i = 0; i < petals.size(); i++) {
    for (int j = i + 1; j < petals.size(); j++) {
      int total = prefix_sum[j + 1] - prefix_sum[i];
      int num = j - i + 1;
      if (total % num == 0) {
        int average = total / num;
        auto end_interval = petals.begin() + j + 1;
        if (find(petals.begin() + i, end_interval, average) != end_interval) {
          count++;
        }
      }
    }
  }
  return count;
}

int main() {
  int n;
  cin >> n;
  vector<int> petals(n);
  for (auto& petal : petals) {
    cin >> petal;
  }
  cout << CountAverageFlower(petals) << endl;
  return 0;
}