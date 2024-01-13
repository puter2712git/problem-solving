#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

/// @brief Compare function for std::sort()
/// @param p1 point in 2D coordinate
/// @param p2 point in 2D coordinate
/// @return true or false
bool compare_points(pair<int, int> p1, pair<int, int> p2)
{
  if (p1.second != p2.second) {
    return p1.second < p2.second;
  }

  return p1.first < p2.first;
}

int main()
{
  int nr_point;
  vector<pair<int, int>> points;

  scanf("%d", &nr_point);
  for (int i = 0; i < nr_point; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    points.push_back({x, y});
  }

  sort(points.begin(), points.end(), compare_points);

  for (int i = 0; i < nr_point; i++) {
    printf("%d %d\n", points[i].first, points[i].second);
  }

  return 0;
}