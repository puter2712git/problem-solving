#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int m;
vector<int> nums;
vector<int> sequence;

void PrintSequences(int currLen)
{
	if (currLen == m) {
		for (int i = 0; i < m; i++) {
			cout << sequence[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		sequence[currLen] = nums[i];
		PrintSequences(currLen + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	nums = vector<int>(n);
	sequence = vector<int>(m);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end(), less<int>());

	PrintSequences(0);

	return 0;
}