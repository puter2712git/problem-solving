#include <iostream>
#include <queue>

using namespace std;


/// @brief Get the shortest time by using BFS.
/// @param _visited graph 1-dimensional array
/// @param _start start number
/// @param _target target number
/// @return shortest time to find
int get_shortest_time(int _visited[], int _start, int _target)
{
  queue<int> bfs;
  bfs.push(_start);

  while (!bfs.empty()) {
    int tmp = bfs.front();
    bfs.pop();

    if (tmp == _target) break;

    for (int i = 0; i < 3; i++) {
      int curr;

      switch (i) {
      case 0:
        curr = tmp - 1;
        break;
      case 1:
        curr = tmp + 1;
        break;
      case 2:
        curr = 2 * tmp;
        break;
      }

      if (curr < 0 || curr > 100000 || _visited[curr] != 0) continue;

      bfs.push(curr);
      _visited[curr] = _visited[tmp] + 1;
    }
  }

  return _visited[_target];
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int start, target;
  int visited[100001] = { 0, };
  
  cin >> start >> target;

  cout << get_shortest_time(visited, start, target) << '\n';

  return 0;
}