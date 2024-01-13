#include <iostream>

using namespace std;

int N;

int memo[1'000'001];

void fill_memo(int n)
{
	for (int i = 3; i <= n; i++) {
		memo[i] = (memo[i - 2] % 15746 + memo[i - 1] % 15746) % 15746;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	memo[0] = 0;
	memo[1] = 1;
	memo[2] = 2;

	cin >> N;
	fill_memo(N);

	cout << memo[N] << "\n";

	return 0;
}