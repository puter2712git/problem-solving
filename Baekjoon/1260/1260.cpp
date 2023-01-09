#include <iostream>
#include <queue>

using namespace std;

int adj_mat[1001][1001] = { 0, };
bool visited[1001] = { false, };

/// @brief Depth first search by using recursion
/// @param _start start vertex
/// @param _nr_vertex number of vertices
void dfs(int _start, int _nr_vertex)
{
  visited[_start] = true;
  printf("%d ", _start);

  for (int i = 1; i <= _nr_vertex; i++) {
    if (adj_mat[_start][i] && !visited[i]) {
      dfs(i, _nr_vertex);
    }
  }
}

/// @brief Breadth first search using queue
/// @param _start start vertex
/// @param _nr_vertex number of vertices
void bfs(int _start, int _nr_vertex)
{
  queue<int> que;
  que.push(_start);

  visited[_start] = true;
  printf("%d ", _start);

  while (!que.empty()) {
    int curr = que.front();
    que.pop();

    for (int i = 1; i <= _nr_vertex; i++) {
      if (adj_mat[curr][i] && !visited[i]) {
        que.push(i);
        visited[i] = true;
        printf("%d ", i);
      }
    }
  }
}

int main()
{
  int nr_vertex, nr_edge, start;
  scanf("%d %d %d", &nr_vertex, &nr_edge, &start);

  for (int i = 0; i < nr_edge; i++) {
    int v1, v2;
    scanf("%d %d", &v1, &v2);
    adj_mat[v1][v2] = 1;
    adj_mat[v2][v1] = 1;
  }

  dfs(start, nr_vertex);
  printf("\n");

  fill_n(visited, 1001, false);

  bfs(start, nr_vertex);
  printf("\n");

  return 0;
}