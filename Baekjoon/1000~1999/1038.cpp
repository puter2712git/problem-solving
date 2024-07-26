#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<string> decreasingNumbers;

void SetDecreasingNumbers()
{
	vector<char> nums = { '9', '8', '7', '6', '5', '4', '3', '2', '1', '0' };
	int len = nums.size();

	for (int i = 1; i <= len; i++) {
		vector<bool> flags(len - i, false);
		flags.insert(flags.end(), i, true);

		do {
			string tmp = "";
			for (int j = 0; j < len; j++) {
				if (flags[j])
					tmp += nums[j];
			}
			decreasingNumbers.push_back(tmp);
		} while (next_permutation(flags.begin(), flags.end()));
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	SetDecreasingNumbers();

	if (N >= decreasingNumbers.size()) {
		cout << "-1\n";
	} else {
		cout << decreasingNumbers[N] << "\n";
	}

	return 0;
}