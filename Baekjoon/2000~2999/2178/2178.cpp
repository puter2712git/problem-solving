#include <iostream>
#include <vector>
#include <queue>

using namespace std;


const pair<int, int> dir[4] = {
  { -1,  0 },
  {  1,  0 },
  {  0, -1 },
  {  0,  1 },
};


/**
 * Solve the @_maze_graph (2-Dimensional vector array) using bfs algorithm.
*/
void solve_maze(vector<vector<int>> &_maze_graph, vector<vector<bool>> &_visited, int _width, int _length)
{
  queue<pair<int, int>> que;
  que.push({ 0, 0 });
  _visited[0][0] = true;

  while (!que.empty()) {
    pair<int, int> tmp = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int nx = tmp.first + dir[i].first;
      int ny = tmp.second + dir[i].second;

      if (nx < 0 || nx >= _width || ny < 0 || ny >= _length || !_maze_graph[ny][nx] || _visited[ny][nx]) {
        continue;
      }

      _visited[ny][nx] = true;
      _maze_graph[ny][nx] = _maze_graph[tmp.second][tmp.first] + 1;
      que.push({ nx, ny });

      if (nx == _width - 1 && ny == _length - 1) {
        return;
      }
    }
  }
}


int main()
{
  int width, length;
  vector<string> maze;
  vector<vector<bool>> visited;
  vector<vector<int>> maze_graph;

  cin >> length >> width;

  for (int i = 0; i < length; i++) {
    string line;
    cin >> line;
    maze.push_back(line);

    visited.push_back(vector<bool>());
    for (int j = 0; j < width; j++) {
      visited[i].push_back(false);
    }
  }

  for (int i = 0; i < length; i++) {
    maze_graph.push_back(vector<int>());
    for (int j = 0; j < width; j++) {
      if (maze[i][j] == '1') {
        maze_graph[i].push_back(1);
      } else {
        maze_graph[i].push_back(0);
      }
    }
  }

  solve_maze(maze_graph, visited, width, length);

  cout << maze_graph[length - 1][width - 1] << '\n';

  return 0;
}