#include <algorithm>
#include <iostream>
#include <vector>

#define INF 2'000'000'000

using namespace std;

int N;
vector<int> liquids;

vector<int> GetLiquids()
{
	vector<int> ret(2);

	int begin = 0;
	int end = N - 1;
	int closest = INF;

	while (begin < end) {
		int sum = liquids[begin] + liquids[end];

		if (closest > abs(sum)) {
			closest = abs(sum);
			ret = { liquids[begin], liquids[end] };
		}

		if (sum < 0) {
			begin++;
		} else {
			end--;
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
	sort(liquids.begin(), liquids.end(), less<int>());

	vector<int> answers = GetLiquids();

	cout << answers[0] << " " << answers[1] << "\n";

	return 0;
}