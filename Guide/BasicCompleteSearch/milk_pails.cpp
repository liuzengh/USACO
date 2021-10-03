#include <fstream>
#include <iostream>

using namespace std;

int MaxAmountMilk(const int x, const int y, const int m) {
  if (m % x == 0 || m % y == 0) {
    return m;
  }
  int max_amount = 0;
  for (int i = 1; i <= m / x; i++) {
    int n = m - i * x;
    max_amount = max(max_amount, m - (n % y));
  }
  return max_amount;
}

int main() {
  int x, y, m;
  ifstream fin("pails.in");
  ofstream fout("pails.out");
  fin >> x >> y >> m;
  fout << MaxAmountMilk(x, y, m) << endl;
  return 0;
}