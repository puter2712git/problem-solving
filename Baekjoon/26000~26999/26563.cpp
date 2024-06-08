#include <iostream>

using namespace std;

int m;
int k;
string self, other;

int GetSameCount()
{
	int ret = 0;
	int len = self.length();

	for (int i = 0; i < len; i++) {
		if (self[i] == other[i]) {
			ret++;
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> m;
	while (m--) {
		cin >> k;
		cin >> self;
		cin >> other;

		int len = self.length();

		int sameCount = GetSameCount();
		int diffCount = len - sameCount;

		int maxCorrectCount = min(k, sameCount) + min(len - k, diffCount);
		cout << maxCorrectCount << "\n";
	}

	return 0;
}