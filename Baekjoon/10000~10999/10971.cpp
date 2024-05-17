#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> costs;
vector<bool> visitFlags;

int minCost = -1;

void FindMinCost(int visitCount, int currCost, int currIndex, int startIndex)
{
	if (visitCount == N) {
		if (minCost == -1 || minCost > currCost) {
			minCost = currCost;
		}
		return;
	}

	if (visitCount == N - 1) {
		if (visitFlags[startIndex] || costs[currIndex][startIndex] == 0)
			return;
		else
			FindMinCost(visitCount + 1, currCost + costs[currIndex][startIndex], startIndex, startIndex);
	}

	for (int i = 0; i < N; i++) {
		if (visitFlags[i] || costs[currIndex][i] == 0)
			continue;

		visitFlags[i] = true;
		FindMinCost(visitCount + 1, currCost + costs[currIndex][i], i, startIndex);
		visitFlags[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	costs = vector<vector<int>>(N, vector<int>(N));
	visitFlags = vector<bool>(N, false);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> costs[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		FindMinCost(0, 0, i, i);
	}

	cout << minCost << "\n";

	return 0;
}