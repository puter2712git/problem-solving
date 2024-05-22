#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> nums;
vector<int> sequence;

void Trace(int currLength = 0, int currIndex = 0)
{
	if (currLength == M) {
		for (int i = 0; i < M; i++) {
			cout << sequence[i] << " ";
		}
		cout << "\n";
		return;
	}

	int tmp = -1;
	for (int i = currIndex; i < N; i++) {
		if (tmp == nums[i])
			continue;

		sequence[currLength] = nums[i];
		tmp = nums[i];
		Trace(currLength + 1, i + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	nums = vector<int>(N);
	sequence = vector<int>(M);

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end(), less<int>());

	Trace();

	return 0;
}