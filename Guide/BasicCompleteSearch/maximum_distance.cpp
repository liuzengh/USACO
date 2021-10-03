#include <iostream>
#include <vector>

using namespace std;

int MaxDistance(const vector<int>& x, const vector<int>& y) {
  int max_distance = 0;
  int n = x.size();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int dx = x[i] - x[j];
      int dy = y[i] - y[j];
      max_distance = max(max_distance, dx * dx + dy * dy);
    }
  }
  return max_distance;
}

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> y[i];
  }
  cout << MaxDistance(x, y) << endl;

  return 0;
}