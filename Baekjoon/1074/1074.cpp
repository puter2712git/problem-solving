#include <cstdio>

using namespace std;

/// @brief Divide and conquer the Z-traversal
/// @param _n integer value (1 <= _n <= 15)
/// @param _r integer value (0 <= _r <= 2^(_n))
/// @param _c integer value (0 <= _c <= 2^(_n))
/// @return the index of (_r, _n) in Z-traversal
int z_traversal(int _n, int _r, int _c)
{
  if (_n == 1) {
    return _c + 2 * _r;
  }

  int half = 1 << (_n - 1);
  int block = half * half;
  int pos;

  if (_c < half && _r < half) {
    pos = 0;
  }
  else if (_c >= half && _r < half) {
    pos = 1;
  }
  else if (_c < half && _r >= half) {
    pos = 2;
  }
  else if (_c >= half && _r >= half) {
    pos = 3;
  }

  return z_traversal(--_n, _r % half, _c % half) + block * pos;
}

int main()
{
  int n;
  int r, c;
  scanf("%d %d %d", &n, &r, &c);

  printf("%d\n", z_traversal(n, r, c));

  return 0;
}