#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

void search(const vector<long long>& weights, const long long total_weight,
            int n, long long group_weight, long long& min_diff) {
  if (n == static_cast<int>(weights.size())) {
    min_diff = min(min_diff, std::abs(total_weight - 2 * group_weight));
    return;
  }
  search(weights, total_weight, n + 1, group_weight + weights[n], min_diff);
  search(weights, total_weight, n + 1, group_weight, min_diff);
}

int main() {
  int n;
  cin >> n;
  vector<long long> weights(n);
  for (auto& weight : weights) {
    cin >> weight;
  }
  long long total_weight =
      accumulate(weights.begin(), weights.end(), static_cast<long long>(0));
  long long min_diff = total_weight;
  search(weights, total_weight, 0, 0, min_diff);
  cout << min_diff << endl;
  return 0;
}