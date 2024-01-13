#include <iostream>

using namespace std;

int N;
int costs[1000][3];

int memo[1000][3];
int min_sum_of_costs = INT32_MAX;

void fill_sum_of_costs()
{
	for (int i = 0; i < 3; i++) {
		memo[0][i] = costs[0][i];
	}

	for (int i = 1; i < N; i++) {
		memo[i][0] = min(memo[i - 1][1] + costs[i][0], memo[i - 1][2] + costs[i][0]);
		memo[i][1] = min(memo[i - 1][0] + costs[i][1], memo[i - 1][2] + costs[i][1]);
		memo[i][2] = min(memo[i - 1][0] + costs[i][2], memo[i - 1][1] + costs[i][2]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> costs[i][j];
		}
	}

	fill_sum_of_costs();

	for (int i = 0; i < 3; i++) {
		min_sum_of_costs = min(min_sum_of_costs, memo[N - 1][i]);
	}

	cout << min_sum_of_costs << "\n";

	return 0;
}