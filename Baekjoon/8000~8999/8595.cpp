#include <iostream>
#include <string>

using namespace std;

int n;
string word;

bool IsNumber(char c) { return c >= '0' && c <= '9'; }

long long GetSumOfHiddenNum()
{
	long long ret = 0;
	int numLength = 0;

	for (int i = 0; i < n; i++) {
		if (IsNumber(word[i])) {
			numLength++;
		} else {
			if (numLength != 0 && numLength < 7) {
				ret += stoi(word.substr(i - numLength, numLength));
			}
			numLength = 0;
		}
	}

	if (numLength != 0 && numLength < 7) {
		ret += stoi(word.substr(n - numLength, numLength));
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	cin >> word;

	cout << GetSumOfHiddenNum() << "\n";

	return 0;
}