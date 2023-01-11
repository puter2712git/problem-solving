#include <iostream>
#include <numeric>

using namespace std;


int get_min_kevin_bacon_user(int _relation[][101], int _nr_user)
{
  for (int k = 1; k <= _nr_user; k++) {
    for (int i = 1; i <= _nr_user; i++) {
      for (int j = 1; j <= _nr_user; j++) {
        if (i == j) continue;

        if (_relation[i][k] != 0 && _relation[k][j] != 0) {
          if (_relation[i][j] == 0) {
            _relation[i][j] = _relation[i][k] + _relation[k][j];
          } else {
            _relation[i][j] = min(_relation[i][j], _relation[i][k] + _relation[k][j]);
          }
        }
      }
    }
  }
  
  int min_kevin_bacon = -1;
  int ret;

  for (int i = 1; i <= _nr_user; i++) {
    int kevin_bacon = 0;

    for (int j = 1; j <= _nr_user; j++) {
      kevin_bacon += _relation[i][j];
    }

    if (min_kevin_bacon == -1 || min_kevin_bacon > kevin_bacon) {
      min_kevin_bacon = kevin_bacon;
      ret = i;
    }
  }

  return ret;
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int nr_user, nr_relation;
  cin >> nr_user >> nr_relation;

  int relation[101][101] = { 0, };

  for (int i = 0; i < nr_relation; i++) {
    int u1, u2;
    cin >> u1 >> u2;

    relation[u1][u2] = 1;
    relation[u2][u1] = 1;
  }

  cout << get_min_kevin_bacon_user(relation, nr_user) << '\n';

  return 0;
}