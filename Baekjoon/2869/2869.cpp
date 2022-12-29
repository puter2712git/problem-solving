#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
  int climb_len, slip_len;
  int stick_len;
  double day;

  scanf("%d %d %d", &climb_len, &slip_len, &stick_len);

  day = ceil(((double)stick_len - slip_len) / (climb_len - slip_len));
  printf("%d\n", (int)day);

  return 0;
}