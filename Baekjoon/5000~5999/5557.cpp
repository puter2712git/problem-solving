#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> nums;

vector<vector<long long>> dp;

void SetDP()
{
	dp = vector<vector<long long>>(N, vector<long long>(21, 0));
	dp[0][nums[0]] = 1;

	for (int i = 1; i < N - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j]) {
				if (j + nums[i] <= 20) {
					dp[i][j + nums[i]] += dp[i - 1][j];
				}
				if (j - nums[i] >= 0) {
					dp[i][j - nums[i]] += dp[i - 1][j];
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	nums = vector<int>(N);

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	SetDP();

	cout << dp[N - 2][nums[N - 1]] << "\n";

	return 0;
}