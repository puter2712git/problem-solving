#include <cstdio>
#include <vector>

using namespace std;

/// @brief Fill the _fibo_memo by dynamic programming
/// @param _fibo_memo empty vector array with pair<int, int>
void fill_memo(vector<pair<int, int>> &_fibo_memo)
{
  _fibo_memo.push_back({ 1, 0 });
  _fibo_memo.push_back({ 0, 1 });

  for (int i = 2; i <= 40; i++) {
    _fibo_memo.push_back({ _fibo_memo[i - 1].first + _fibo_memo[i - 2].first, _fibo_memo[i - 1].second + _fibo_memo[i - 2].second });
  }
}

int main()
{
  int nr_testcase;
  scanf("%d", &nr_testcase);
  
  vector<pair<int, int>> fibo_memo;
  
  fill_memo(fibo_memo);


  for (int i = 0; i < nr_testcase; i++) {
    int fibo;
    scanf("%d", &fibo);

    printf("%d %d\n", fibo_memo[fibo].first, fibo_memo[fibo].second);
  }
}