#include <cstdio>
#include <vector>

using namespace std;

/// @brief Print the array
/// @param _nums number counted array
void print_counts(vector<int> &_counted_nums)
{
  for (int i = 1; i <= 10000; i++) {
    for (int j = 0; j < _counted_nums[i]; j++) {
      printf("%d\n", i);
    }
  }
}

int main()
{
  int nr_num;
  vector<int> counted_nums(10001);  // 4 byte * 10001 = 40004 byte = 0.04 MB

  scanf("%d", &nr_num);
  for (int i = 0; i < nr_num; i++) {
    int num;
    scanf("%d", &num);
    counted_nums[num]++;
  }

  print_counts(counted_nums);

  return 0;
}