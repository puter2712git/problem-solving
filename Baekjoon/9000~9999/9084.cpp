#include <iostream>
#include <vector>

using namespace std;

int T;
int N;
int M;
vector<int> coins;

vector<long long> dp;

void SetDP()
{
	dp.clear();
	dp = vector<long long>(M + 1, 0);
	dp[0] = 1;

	for (int coin : coins) {
		for (int i = 1; i <= M; i++) {
			if (i >= coin) {
				dp[i] += dp[i - coin];
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> N;
		coins.clear();
		coins = vector<int>(N);

		for (int i = 0; i < N; i++) {
			cin >> coins[i];
		}
		cin >> M;

		SetDP();
		cout << dp[M] << "\n";
	}

	return 0;
}