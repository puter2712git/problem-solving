#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> costs;

int maxCost;
int sumOfCost;

int GetThresholdCost()
{
	int begin = 0;
	int end = maxCost;
	int mid;
	int tmpSum;

	while (begin <= end) {
		mid = (begin + end) / 2;
		tmpSum = 0;

		for (int i = 0; i < N; ++i) {
			tmpSum += costs[i] < mid ? costs[i] : mid;
		}

		if (tmpSum <= M) {
			begin = mid + 1;
		} else {
			end = mid - 1;
		}
	}

	return end;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	costs = vector<int>(N);
	for (int i = 0; i < N; ++i) {
		cin >> costs[i];
		if (i == 0) {
			maxCost = costs[i];
		} else {
			maxCost = maxCost < costs[i] ? costs[i] : maxCost;
		}

		sumOfCost += costs[i];
	}
	cin >> M;

	if (sumOfCost <= M) {
		cout << maxCost << "\n";
	} else {
		cout << GetThresholdCost() << "\n";
	}

	return 0;
}