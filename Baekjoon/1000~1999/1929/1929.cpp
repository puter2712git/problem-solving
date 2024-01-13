#include <iostream>
#include <vector>

using namespace std;

void checkPrime(vector<bool> &_nums, int _end) {
	for (int i = 2; i * i <= _end; i++) {
		for (int j = i * i; j <= _end; j += i) {
			_nums[j] = false;
		}
	}

	return;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int start, end;
	cin >> start >> end;

	vector<bool> nums(end + 1);
	fill(nums.begin(), nums.end(), true);
	nums[1] = false;

	checkPrime(nums, end);

	for (int i = start; i <= end; i++) {
		if (nums[i]) {
			cout << i << '\n';
		}
	}

	return 0;
}