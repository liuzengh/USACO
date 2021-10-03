#include <iomanip>
#include <iostream>
#include <unordered_set>

using namespace std;

bool IsDistinctDigits(long long n) {
  unordered_set<int> num_set;
  while (n) {
    int reminder = n % 10;
    if (num_set.count(reminder) != 0) {
      return false;
    };
    num_set.insert(reminder);
    n /= 10;
  }
  return true;
}

void ValidEquation(const long long n) {
  constexpr long long kLowerBound = 1;
  constexpr long long kUpperBound = 9876543210;

  for (long long denominator = kLowerBound; denominator <= kUpperBound;
       denominator++) {
    long long nominator = denominator * n;
    if (kUpperBound < nominator) {
      break;
    }
    if (!IsDistinctDigits(denominator) || !IsDistinctDigits(nominator)) {
      continue;
    }
    cout << nominator << " / " << denominator << " = " << n << endl;
  }
}

int main() {
  int num_case;
  cin >> num_case;
  bool first_line = true;

  for (int i = 0; i < num_case; i++) {
    long long n;
    cin >> n;
    if (first_line) {
      first_line = false;
    } else {
      cout << endl;
    }
    ValidEquation(n);
  }
  return 0;
}