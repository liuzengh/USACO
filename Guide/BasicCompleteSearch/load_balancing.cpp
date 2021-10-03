#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Location {
  int x;
  int y;
  bool operator<(const Location& other) {
    return (x < other.x) || (x == other.x && y < other.y);
  }
};

int WhichRegion(const Location& origin_point, const Location& target_point) {
  int dx = target_point.x - origin_point.x;
  int dy = target_point.y - origin_point.y;
  if (0 < dx && 0 < dy) {
    return 0;
  }
  if (0 < dx && dy < 0) {
    return 3;
  }
  if (dx < 0 && 0 < dy) {
    return 1;
  }
  if (dx < 0 && dy < 0) {
    return 2;
  }
  return -1;
}

int LoadBalancing(const vector<Location>& locations) {
  constexpr int kRegion = 4;
  vector<int> dxs = {-1, 1};
  vector<int> dys = {-1, 1};
  int max_num = locations.size();
  for (const auto& location : locations) {
    for (auto dx : dxs) {
      for (auto dy : dys) {
        vector<int> count(kRegion, 0);
        Location origin_point = {dx + location.x, dy + location.y};
        for (const auto& target_point : locations) {
          count[WhichRegion(origin_point, target_point)]++;
        }
        max_num = min(*max_element(count.begin(), count.end()), max_num);
      }
    }
  }
  return max_num;
}

int main() {
  int n, b;
  ifstream fin("balancing.in");
  ofstream fout("balancing.out");
  fin >> n >> b;
  vector<Location> locations(n);
  for (auto& location : locations) {
    fin >> location.x >> location.y;
  }

  fout << LoadBalancing(locations) << endl;
  fin.close();
  fout.close();
  return 0;
}