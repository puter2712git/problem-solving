#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> liquids;

pair<int, int> GetTwoLiquids()
{
	pair<int, int> ret;

	int beginIndex = 0;
	int endIndex = N - 1;
	int closest = 2'000'000'000;

	while (beginIndex < endIndex) {
		int pH = liquids[beginIndex] + liquids[endIndex];

		if (closest > abs(pH)) {
			closest = abs(pH);
			ret = { liquids[beginIndex], liquids[endIndex] };
		}

		if (pH < 0) {
			beginIndex++;
		} else {
			endIndex--;
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	liquids = vector<int>(N);
	for (int i = 0; i < N; i++) {
		cin >> liquids[i];
	}

	pair<int, int> liquids = GetTwoLiquids();
	cout << liquids.first << " " << liquids.second << "\n";

	return 0;
}