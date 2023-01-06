#include <cstdio>
#include <string>

#define MAX_STRING_SIZE 51

using namespace std;

const int r = 31;
const int M = 1234567891;

/// @brief Return the hash value of the string
/// @param _str string
/// @param _str_len size of the _str
/// @return hash value of the _str
long long hash_function(string _str, int &_str_len)
{
  long long hash_value = 0;
  long long mult;
  int times;

  for (int i = 0; i < _str_len; i++) {
    mult = 1;
    times = i;
    while (times > 0) {
      mult *= r;
      mult %= M;

      times--;
    }

    hash_value += (_str[i] - 'a' + 1) * mult;
    hash_value %= M;
  }

  return hash_value;
}

int main()
{
  int str_len;
  char str[MAX_STRING_SIZE];

  scanf("%d", &str_len);
  scanf("%s", str);

  printf("%lld\n", hash_function(str, str_len));

  return 0;
}