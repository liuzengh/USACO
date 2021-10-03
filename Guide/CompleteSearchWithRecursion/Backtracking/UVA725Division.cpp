#include <iomanip>
#include <iostream>
#include <unordered_set>

using namespace std;

bool ValidEquation(const int n) {
  constexpr int kLowerBound = 1234;
  constexpr int kUpperBound = 98765;
  constexpr int kNumDigit = 10;
  constexpr int kOutputWidth = 5;

  bool is_valid = false;
  unordered_set<int> num_set;
  for (int denominator = kLowerBound; denominator <= kUpperBound;
       denominator++) {
    int nominator = denominator * n;
    if (kUpperBound < nominator) {
      break;
    }
    // Check
    if (denominator < 10000) {
      num_set.insert(0);
    }
    for (int x = denominator; x != 0; x /= 10) {
      num_set.insert(x % 10);
    }

    if (nominator < 10000) {
      num_set.insert(0);
    }
    for (int x = nominator; x != 0; x /= 10) {
      num_set.insert(x % 10);
    }
    if (num_set.size() == kNumDigit) {
      is_valid = true;
      cout << setw(kOutputWidth) << setfill('0') << nominator << " / "
           << setw(kOutputWidth) << setfill('0') << denominator << " = " << n
           << endl;
    }
    num_set.clear();
  }
  return is_valid;
}

int main() {
  int n;
  bool first_line = true;
  while (cin >> n && n != 0) {
    if (first_line) {
      first_line = false;
    } else {
      cout << endl;
    }
    if (!ValidEquation(n)) {
      cout << "There are no solutions for " << n << "." << endl;
    }
  }
  return 0;
}