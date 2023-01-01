#include <cstdio>

using namespace std;

int main()
{
  int nr_testcase;
  int height, width, num;

  scanf("%d", &nr_testcase);

  for (int i = 0; i < nr_testcase; i++) {
    scanf("%d %d %d", &height, &width, &num);

    int floor; // 층 번호
    if (num % height == 0) {
      floor = height;
    }
    else {
      floor = num % height;
    }

    int room; // 호수
    if (num % height == 0) {
      room = num / height;
    }
    else {
      room = num / height + 1;
    }

    int room_number = floor * 100 + room;
    printf("%d\n", room_number);
  }

  return 0;
}