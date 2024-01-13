#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;

int dp[100'001];

int get_max_sum()
{
	int ret = INT32_MIN;

	dp[0] = arr[0];
	ret = dp[0];

	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		ret = max(ret, dp[i]);
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	cout << get_max_sum() << "\n";

	return 0;
}