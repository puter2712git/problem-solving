#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> levels;

int GetUnionLevel(int level)
{
	if (level < 60) {
		return 0;
	} else if (level < 100) {
		return 1;
	} else if (level < 140) {
		return 2;
	} else if (level < 200) {
		return 3;
	} else if (level < 250) {
		return 4;
	} else {
		return 5;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	levels = vector<int>(N);

	for (int i = 0; i < N; i++) {
		cin >> levels[i];
	}

	sort(levels.begin(), levels.end(), greater<int>());

	int levelSum = 0;
	int increasedAbility = 0;

	int len = N < 42 ? N : 42;
	for (int i = 0; i < len; i++) {
		levelSum += levels[i];
		increasedAbility += GetUnionLevel(levels[i]);
	}

	cout << levelSum << " " << increasedAbility << "\n";

	return 0;
}