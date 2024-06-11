#include <iostream>
#include <vector>

using namespace std;

int T;
int N;
vector<int> stocks;

long long GetMaxProfit()
{
	long long ret = 0;

	int maxIndex = N - 1;
	for (int i = N - 2; i >= 0; i--) {
		if (stocks[i] < stocks[maxIndex])
			ret += stocks[maxIndex] - stocks[i];
		else
			maxIndex = i;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> N;
		stocks.clear();
		stocks = vector<int>(N);
		for (int i = 0; i < N; i++) {
			cin >> stocks[i];
		}

		cout << GetMaxProfit() << "\n";
	}

	return 0;
}