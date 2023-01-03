#include <cstdio>

using namespace std;

/// @brief Get the factorial of _n
/// @param _n integer value
/// @return factorial of _n
int get_factorial(int _n)
{
  int factorial = 1;

  for (int i = _n; i >= 1; i--) {
    factorial *= i;
  }

  return factorial;
}

/// @brief Get the binomial coefficient of (n, k)
/// @param _n integer value
/// @param _k integer value but less than or equal to _n
/// @return binomial coefficient of (n, k)
int get_binomial(int _n, int _k)
{
  return get_factorial(_n) / (get_factorial(_n - _k) * get_factorial(_k));
}

int main()
{
  int n, k;
  scanf("%d %d", &n, &k);

  printf("%d\n", get_binomial(n, k));

  return 0;
}