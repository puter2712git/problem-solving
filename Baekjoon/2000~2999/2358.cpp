#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	map<int, int> xMap, yMap;
	int answer = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		xMap[x]++;
		yMap[y]++;
	}

	for (auto it : xMap) {
		if (it.second > 1) {
			answer++;
		}
	}

	for (auto it : yMap) {
		if (it.second > 1) {
			answer++;
		}
	}

	cout << answer << "\n";

	return 0;
}