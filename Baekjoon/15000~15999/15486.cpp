#include <iostream>
#include <vector>

using namespace std;

struct Work
{
	int time;
	int gold;
};

int N;
vector<Work> works;
vector<int> dp;

void SetDP()
{
	dp = vector<int>(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		dp[i] = max(dp[i], dp[i - 1]);
		int endTime = i + works[i].time - 1;

		if (endTime <= N) {
			dp[endTime] = max(dp[endTime], dp[i - 1] + works[i].gold);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	works = vector<Work>(N + 1, { -1, -1 });
	for (int i = 1; i <= N; i++) {
		cin >> works[i].time >> works[i].gold;
	}

	SetDP();

	cout << dp[N] << "\n";

	return 0;
}