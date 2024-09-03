#include <iostream>

using namespace std;

int testcaseCount;
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> testcaseCount;
	for (int i = 0; i < testcaseCount; i++) {
		cin >> N;

		int cutCount = 0;
		if (N % 2 == 0)
			cutCount += N / 2;
		else
			cutCount += N / 2 + 1;

		if (N % 6 == 0 || N % 6 == 4)
			cutCount += N / 3;
		else
			cutCount += N / 3 + 1;

		cout << cutCount << "\n";
	}

	return 0;
}