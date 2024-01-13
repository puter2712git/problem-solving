#include <cstdio>
#include <utility>

#define MAX_GROUND_HEIGHT 256

using namespace std;

/// @brief Flat the ground with _ground_height
/// @param _ground 2-dimensional array
/// @param _ground_height height of the ground to be flatted
/// @param _width width of the ground
/// @param _length length of the ground
/// @param _nr_block the number of block in inventory
/// @param _min_time taking time to be flatten
/// @param _max_height maximum height (to compare when the @_min_time is same)
void flat_ground(int _ground[][501], int _ground_height, int _width, int _length, int _nr_block, int &_min_time, int &_max_height)
{
  int time = 0;
  int block = _nr_block;

  for (int i = 0; i < _width; i++) {
    for (int j = 0; j < _length; j++) {
      block -= _ground_height - _ground[i][j];
    }
  }

  for (int i = 0; i < _width; i++) {
    for (int j = 0; j < _length; j++) {
      if (_ground[i][j] > _ground_height) {
        time += 2 * (_ground[i][j] - _ground_height);
        continue;
      }

      if (_ground[i][j] < _ground_height) {
        if (block >= 0) {
          time += _ground_height - _ground[i][j];
          continue;
        }
        else {
          return;
        }
      }
    }
  }

  if (_min_time == -1 || _min_time > time) {
    _min_time = time;
    _max_height = _ground_height;
  }
  else if (_min_time == time) {
    if (_max_height < _ground_height) {
      _max_height = _ground_height;
    }
  }
}

/// @brief Get the minimum time and the height for flatting the ground
/// @param _ground 2-dimensional array
/// @param _width width of the ground
/// @param _length length of the ground
/// @param _nr_block the number of block in inventory
/// @return pair of min_time and height of the ground
pair<int, int> get_flatting_info(int _ground[][501], int _width, int _length, int _nr_block)
{
  int min_time = -1;
  int max_height = -1;

  for (int ground_height = 0; ground_height <= MAX_GROUND_HEIGHT; ground_height++) {
    flat_ground(_ground, ground_height, _width, _length, _nr_block, min_time, max_height);
  }

  return { min_time, max_height };
}

int main()
{
  int width, length, nr_block;
  scanf("%d %d %d", &width, &length, &nr_block);

  int ground[width][501];
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < length; j++) {
      scanf("%d", &ground[i][j]);
    }
  }

  pair<int, int> answer = get_flatting_info(ground, width, length, nr_block);

  printf("%d %d\n", answer.first, answer.second);

  return 0;
}