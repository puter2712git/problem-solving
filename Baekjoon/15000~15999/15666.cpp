#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> nums;
vector<int> arr;

void Trace(int currLen, int lastIndex)
{
	if (currLen == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	int tmp = -1;

	for (int i = lastIndex; i < N; i++) {
		if (tmp == nums[i])
			continue;

		tmp = nums[i];
		arr[currLen] = nums[i];
		Trace(currLen + 1, i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	nums = vector<int>(N);
	arr = vector<int>(M);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end(), less<int>());

	Trace(0, 0);

	return 0;
}