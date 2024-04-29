#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct SerialNumber
{
	string code;
	bool operator<(const SerialNumber &s) const
	{
		if (code.length() != s.code.length()) {
			return code.length() < s.code.length();
		}

		int sumA = 0;
		int sumB = 0;

		for (int i = 0; i < code.length(); ++i) {
			if (code[i] >= '0' && code[i] <= '9') {
				sumA += code[i] - '0';
			}
		}

		for (int i = 0; i < s.code.length(); ++i) {
			if (s.code[i] >= '0' && s.code[i] <= '9') {
				sumB += s.code[i] - '0';
			}
		}

		if (sumA != sumB) {
			return sumA < sumB;
		}

		return code < s.code;
	}
};

int N;
vector<SerialNumber> serialNumbers;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		string num;
		cin >> num;

		SerialNumber tmp;
		tmp.code = num;
		serialNumbers.push_back(tmp);
	}

	sort(serialNumbers.begin(), serialNumbers.end(), less<SerialNumber>());

	for (int i = 0; i < N; ++i) {
		cout << serialNumbers[i].code << "\n";
	}

	return 0;
}