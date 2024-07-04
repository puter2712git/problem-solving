#include <iostream>
#include <vector>

#define INF 987'654'321

using namespace std;

int n, k;
vector<int> coins;
vector<int> records;

void FillRecords()
{
	records[0] = 0;

	for (const auto &coin : coins) {
		for (int i = coin; i <= k; i++) {
			records[i] = min(records[i], records[i - coin] + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	coins = vector<int>(n);
	records = vector<int>(k + 1, INF);

	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	FillRecords();

	if (records[k] == INF) {
		cout << "-1\n";
	} else {
		cout << records[k] << "\n";
	}

	return 0;
}