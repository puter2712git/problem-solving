#include <iostream>
#include <vector>

using namespace std;


/// @brief Add the paper count.
/// @param _papers 2-dimensional vector for papers
/// @param _nr_minus ref integer value
/// @param _nr_zero ref integer value
/// @param _nr_one ref integer value
/// @param _x start point
/// @param _y start point
void add_paper_count(vector<vector<int>> &_papers, int &_nr_minus, int &_nr_zero, int &_nr_one, int _x, int _y)
{
  switch (_papers[_y][_x]) {
  case -1:
    _nr_minus++;
    break;
  case 0:
    _nr_zero++;
    break;
  case 1:
    _nr_one++;
    break;
  }
}


/// @brief Check that the number of the _papers is all same.
/// @param _papers 2-dimensional vector for papers
/// @param _size size of the _papers
/// @param _x start point
/// @param _y start point
/// @return true if all same, false if not
bool is_all_same(vector<vector<int>> &_papers, int _size, int _x, int _y)
{
  int num = _papers[_y][_x];

  for (int i = _y; i < _y + _size; i++) {
    for (int j = _x; j < _x + _size; j++) {
      if (_papers[i][j] != num) {
        return false;
      }
    }
  }

  return true;
}


/// @brief Count the paper by reference.
/// @param _papers 2-dimensional vector for papers
/// @param _nr_minus ref integer value
/// @param _nr_zero ref integer value
/// @param _nr_one ref integer value
/// @param _size size of the _papers
/// @param _x start point
/// @param _y start point
void count_paper(vector<vector<int>> &_papers, int &_nr_minus, int &_nr_zero, int &_nr_one, int _size, int _x = 0, int _y = 0)
{
  if (_size == 1) {
    add_paper_count(_papers, _nr_minus, _nr_zero, _nr_one, _x, _y);
    return;
  }

  if (is_all_same(_papers, _size, _x, _y)) {
    add_paper_count(_papers, _nr_minus, _nr_zero, _nr_one, _x, _y);
    return;
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      count_paper(_papers, _nr_minus, _nr_zero, _nr_one, _size / 3, _x + j * (_size / 3), _y + i * (_size / 3));
    }
  }
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  vector<vector<int>> papers;

  cin >> n;
  for (int i = 0; i < n; i++) {
    papers.push_back(vector<int>());
    for (int j = 0; j < n; j++) {
      int paper;
      cin >> paper;
      papers[i].push_back(paper);
    }
  }

  int nr_minus = 0;
  int nr_zero = 0;
  int nr_one = 0;

  count_paper(papers, nr_minus, nr_zero, nr_one, n);
  cout << nr_minus << '\n';
  cout << nr_zero << '\n';
  cout << nr_one << '\n';

  return 0;
}