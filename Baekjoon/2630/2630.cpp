#include <iostream>
using namespace std;

#define MAX_PAPER_SIZE 1 << 7

bool is_all_same(int _papers[][MAX_PAPER_SIZE], int _x, int _y, int _size)
{
  int num = _papers[_y][_x];
  for (int i = _y; i < _y + _size; i++) {
    for (int j = _x; j < _x + _size; j++) {
      if (_papers[i][j] != num)
        return false;
    }
  }

  return true;
}

void count_paper(int _papers[][MAX_PAPER_SIZE], int _x, int _y, int _size, int &_nr_white, int &_nr_blue)
{
  if (is_all_same(_papers, _x, _y, _size)) {
    switch (_papers[_y][_x]) {
    case 0:
      _nr_white++;
      break;
    case 1:
      _nr_blue++;
      break;
    }
    return;
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      count_paper(_papers, _x + j * _size / 2, _y + i * _size / 2, _size / 2, _nr_white, _nr_blue);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int paper_len;
  int papers[MAX_PAPER_SIZE][MAX_PAPER_SIZE];

  cin >> paper_len;
  for (int i = 0; i < paper_len; i++) {
    for (int j = 0; j < paper_len; j++) {
      cin >> papers[i][j];
    }
  }

  int nr_white = 0, nr_blue = 0;
  count_paper(papers, 0, 0, paper_len, nr_white, nr_blue);

  cout << nr_white << '\n';
  cout << nr_blue << '\n';

  return 0;
}