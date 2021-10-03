#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int MaxTriangleArea(const vector<int>& x, const vector<int>& y, const int n) {
  int max_area = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (x[i] == x[j] && y[i] == y[k]) {
          int area = std::abs((x[i] - x[k]) * (y[i] - y[j]));
          max_area = max(max_area, area);
        }
      }
    }
  }
  return max_area;
}

int main() {
  ifstream fin("triangles.in");
  ofstream fout("triangles.out");
  int n;
  fin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (int i = 0; i < n; i++) {
    fin >> x[i] >> y[i];
  }
  fout << MaxTriangleArea(x, y, n) << endl;
  fin.close();
  fout.close();
  return 0;
}