#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> coins;
vector<long long> records;

void Fill()
{
	records[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = coins[i]; j <= k; j++) {
			records[j] += records[j - coins[i]];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	coins = vector<int>(n + 1);
	records = vector<long long>(k + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> coins[i];
	}

	Fill();

	cout << records[k] << "\n";

	return 0;
}