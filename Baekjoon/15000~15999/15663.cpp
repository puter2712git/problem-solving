#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> nums;
vector<bool> visitFlags;
vector<int> sequence;

void Trace(int currLen)
{
	if (currLen == M) {
		for (int i = 0; i < M; ++i) {
			cout << sequence[i] << " ";
		}
		cout << "\n";
		return;
	}

	int tmp = 0;
	for (int i = 0; i < N; ++i) {
		if (!visitFlags[i] && tmp != nums[i]) {
			sequence[currLen] = nums[i];
			tmp = nums[i];

			visitFlags[i] = true;
			Trace(currLen + 1);
			visitFlags[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	nums = vector<int>(N);
	visitFlags = vector<bool>(N, false);
	sequence = vector<int>(M);
	for (int i = 0; i < N; ++i) {
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end(), less<int>());

	Trace(0);

	return 0;
}