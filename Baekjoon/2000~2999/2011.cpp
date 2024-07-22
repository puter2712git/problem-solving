#include <iostream>
#include <vector>

using namespace std;

string password;
vector<int> dp;

int GetCaseCount()
{
	if (password[0] == '0')
		return 0;

	int len = password.length();

	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= len; i++) {
		if (password[i - 1] != '0') {
			dp[i] = dp[i - 1] % 1'000'000;
		}

		int partition = (password[i - 2] - '0') * 10 + (password[i - 1] - '0');
		if (partition >= 10 && partition <= 26)
			dp[i] = (dp[i] + dp[i - 2]) % 1'000'000;
	}

	return dp[len];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> password;
	dp = vector<int>(password.length() + 1, 0);

	cout << GetCaseCount() << "\n";

	return 0;
}