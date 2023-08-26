#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> wires;

int memo[100];

bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

int find_cut_count()
{
	for (int i = 0; i < n; i++) {
		memo[i] = 1;

		for (int j = 0; j < i; j++) {
			if (wires[i].second > wires[j].second) {
				memo[i] = max(memo[i], memo[j] + 1);
			}
		}
	}

	return n - *max_element(memo, memo + n);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		wires.push_back({ start, end });
	}

	sort(wires.begin(), wires.end(), compare);

	cout << find_cut_count() << "\n";

	return 0;
}