#include <cstdio>
#include <stack>

using namespace std;

int main()
{
  stack<int> nums;
  int nr_num;
  int num;

  scanf("%d", &nr_num);

  for (int i = 0; i < nr_num; i++) {
    scanf("%d", &num);

    if (num == 0) {
      nums.pop();
    }
    else {
      nums.push(num);
    }
  }

  int sum = 0;
  while (!nums.empty()) {
    sum += nums.top();
    nums.pop();
  }

  printf("%d\n", sum);

  return 0;
}