#include <iostream>
#include <vector>
#include <string>

using namespace std;


/// @brief Check that the number is all same in the size of the @vid.
/// @param vid vector<string>
/// @param size size of the @vid (length of vid[0])
/// @param x start point
/// @param y start point
/// @return return true if same
bool is_all_same(vector<string> &vid, int size, int x, int y)
{
  char num = vid[y][x];

  for (int i = y; i < y + size; i++) {
    for (int j = x; j < x + size; j++) {
      if (num != vid[i][j]) {
        return false;
      }
    }
  }

  return true;
}


/// @brief Print the result of quad tree of @vid
/// @param vid vector<string>
/// @param size size of @vid (length of vid[0])
/// @param x start point
/// @param y start point
void print_quad_tree(vector<string> &vid, int size, int x = 0, int y = 0)
{
  if (size == 1) {
    cout << vid[y][x];
    return;
  }

  if (is_all_same(vid, size, x, y)) {
    cout << vid[y][x];
    return;
  }

  cout << '(';
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      print_quad_tree(vid, size / 2, x + j * size / 2, y + i * size / 2);
    }
  }
  cout << ')';
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  vector<string> video;

  cin >> n;
  for (int i = 0; i < n; i++) {
    string nums;
    cin >> nums;
    video.push_back(nums);
  }

  print_quad_tree(video, n);
  cout << '\n';

  return 0;
}