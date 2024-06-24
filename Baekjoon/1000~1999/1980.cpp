#include <iostream>
#include <limits>

using namespace std;

int n, m, t;

void Check()
{
	int minCokeTime = numeric_limits<int>::max();
	int maxHamburgerCount = 0;

	int i = 0;
	int smallTime = min(n, m);
	int bigTime = max(n, m);
	while (smallTime * i <= t) {
		int time = t - smallTime * i;
		int hamburgerCount = i + time / bigTime;
		int cokeTime = time % bigTime;

		if (minCokeTime > cokeTime) {
			minCokeTime = cokeTime;
			maxHamburgerCount = hamburgerCount;
		} else if (minCokeTime == cokeTime) {
			maxHamburgerCount = max(maxHamburgerCount, hamburgerCount);
		}

		i++;
	}

	cout << maxHamburgerCount << " " << minCokeTime << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> t;

	Check();

	return 0;
}