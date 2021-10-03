#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Interval {
  int start;
  int end;
  bool operator<(const Interval& rhs) const {
    return (start < rhs.start) || (start == rhs.start && end < rhs.end);
  }
};

int AmountCoverTime(const vector<Interval>& points, const int fire_point) {
  if (points.empty()) {
    return 0;
  }
  int amount = 0;
  bool has_left_interval = false;
  Interval left_interval;

  for (int i = 0; i < points.size(); i++) {
    if (i == fire_point) {
      continue;
    }
    if (!has_left_interval) {
      left_interval = points[i];
      amount += left_interval.end - left_interval.start;
      has_left_interval = true;
      continue;
    }
    if (points[i].start <= left_interval.end) {
      if (left_interval.start < points[i].end) {
        amount += (points[i].end - left_interval.end);
        left_interval.end = points[i].end;
      }
    } else {
      left_interval = points[i];
      amount += left_interval.end - left_interval.start;
    }
  }
  return amount;
}

int main() {
  ifstream fin("lifeguards.in");
  ofstream fout("lifeguards.out");
  int n;
  fin >> n;
  vector<Interval> points(n);
  for (auto& point : points) {
    fin >> point.start >> point.end;
  }
  sort(points.begin(), points.end());
  int max_amount = 0;
  for (int i = 0; i < n; i++) {
    max_amount = max(max_amount, AmountCoverTime(points, i));
  }
  fout << max_amount << endl;
  return 0;
}