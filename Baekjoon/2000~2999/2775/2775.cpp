#include <cstdio>

using namespace std;


/* Dynamic Programming */
void memoize(int _dp[][15])
{
	/* 0층의 호실들 값 할당 */
	for (int room = 1; room < 15; room++) {
		_dp[0][room] = room;
	}

	/* 1층의 1호실부터 값을 할당 */
	for (int floor = 1; floor < 15; floor++) {
		for (int room = 1; room < 15; room++) {
			for (int i = 1; i <= room; i++) {
				_dp[floor][room] += _dp[floor - 1][i];
			}
		}
	}

	return;
}


int main()
{
	int living_people[15][15] = { 0, };
	memoize(living_people);

	int nr_testcase;
	scanf("%d", &nr_testcase);

	for (int i = 0; i < nr_testcase; i++) {
		int floor, room;
		scanf("%d", &floor);
		scanf("%d", &room);

		printf("%d\n", living_people[floor][room]);
	}

	return 0;
}