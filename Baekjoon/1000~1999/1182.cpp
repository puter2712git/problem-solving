#include <iostream>
#include <vector>

using namespace std;

int N;
int S;
vector<int> nums;
vector<bool> isVisiteds;

int countOfSum;

void CountPartialSum(int len, int sum, int index)
{
	if (len > 0 && sum == S) {
		++countOfSum;
	}

	for (int i = 0; i < N; ++i) {
		if (isVisiteds[i] || index > i)
			continue;

		isVisiteds[i] = true;
		CountPartialSum(len + 1, sum + nums[i], i);
		isVisiteds[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> S;
	nums = vector<int>(N, 0);
	isVisiteds = vector<bool>(N, false);
	for (int i = 0; i < N; ++i) {
		cin >> nums[i];
	}

	CountPartialSum(0, 0, 0);

	cout << countOfSum << "\n";

	return 0;
}