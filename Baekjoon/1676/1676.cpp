#include <iostream>

using namespace std;


/// @brief Count the zeros in @_n!.
/// @param _n target integer
/// @param _zero_counts array of count (zero)
void count_zero(int _n, int _zero_counts[])
{
  int count;

  _zero_counts[0] = 0;

  for (int i = 1; i <= _n; i++) {
    int num = i;
    count = _zero_counts[i - 1];

    while (num % 5 == 0) {
      count++;
      num /= 5;
    }

    _zero_counts[i] = count;
  }
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  int zero_counts[501] = { 0, };
  count_zero(n, zero_counts);

  cout << zero_counts[n] << '\n';

  return 0;
}