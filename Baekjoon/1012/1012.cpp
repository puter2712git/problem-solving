#include <cstdio>
#include <utility>

using namespace std;

const int dx[4] = { -1, 1,  0, 0 };
const int dy[4] = {  0, 0, -1, 1 };

/// @brief Depth first search the @_field
/// @param _field 2-dimensional array
/// @param _width width of the @_field
/// @param _length length of the @_field
/// @param _x start point
/// @param _y start point
void dfs(pair<int, bool> _field[][50], int _width, int _length, int _x, int _y)
{
  for (int i = 0; i < 4; i++) {
    int nx = _x + dx[i];
    int ny = _y + dy[i];

    if (nx < 0 || nx >= _width || ny < 0 || ny >= _length) {
      continue;
    }

    if (_field[ny][nx].first && !_field[ny][nx].second) {
      _field[ny][nx].second = true;
      dfs(_field, _width, _length, nx, ny);
    }
  }
}

int main()
{
  int nr_testcase;
  int width, length, nr_cabbage;

  scanf("%d", &nr_testcase);

  for (int i = 0; i < nr_testcase; i++) {
    scanf("%d %d %d", &width, &length, &nr_cabbage);

    pair<int, bool> field[length][50] = { make_pair(0, false), };
    int nr_bug = 0;

    int x, y;
    for (int i = 0; i < nr_cabbage; i++) {
      scanf("%d %d", &x, &y);
      field[y][x].first = 1;
    }

    for (int i = 0; i < length; i++) {
      for (int j = 0; j < width; j++) {
        if (field[i][j].first && !field[i][j].second) {
          nr_bug++;
          field[i][j].second = true;
          dfs(field, width, length, j, i);
        }
      }
    }

    printf("%d\n", nr_bug);
  }

  return 0;
}