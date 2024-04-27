#include <iostream>

using namespace std;

long long X;
long long Y;
int Z;

int GetCurrentWinRate() { return Y * 100 / X; }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> X >> Y;
	Z = Y * 100 / X;

	if (Z >= 99) {
		cout << -1 << "\n";
		return 0;
	}

	int begin = 0;
	int end = 1'000'000'000;

	while (begin <= end) {
		int mid = (begin + end) / 2;
		int winrate = (Y + mid) * 100 / (X + mid);

		if (Z < winrate)
			end = mid - 1;
		else
			begin = mid + 1;
	}

	cout << begin << "\n";
	return 0;
}