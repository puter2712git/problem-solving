#include <iostream>
#include <vector>

using namespace std;


/**
 * Fill the @_max_score vector using Dynamic Programming.
*/
void fill_score(const vector<int> &_stairs, vector<int> &_max_score)
{
  const int size = _stairs.size();

  _max_score.push_back(_stairs[0]);
  _max_score.push_back(_stairs[0] + _stairs[1]);
  _max_score.push_back(max(_stairs[0] + _stairs[2], _stairs[1] + _stairs[2]));

  for (int i = 3; i < size; i++) {
    _max_score.push_back(max(_max_score[i - 2] + _stairs[i], _max_score[i - 3] + _stairs[i - 1] + _stairs[i]));
  }
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int nr_stair;
  vector<int> stairs;

  cin >> nr_stair;
  for (int i = 0; i < nr_stair; i++) {
    int score;
    cin >> score;
    stairs.push_back(score);
  }

  vector<int> max_score;
  fill_score(stairs, max_score);

  cout << max_score[nr_stair - 1] << '\n';

  return 0;
}