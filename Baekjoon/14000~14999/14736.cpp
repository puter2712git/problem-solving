#include <iostream>
#include <vector>

using namespace std;

int N;
int K, A;
int t, s;
int minTime = 123456789;

int GetTime()
{
	int cycleTime = t + s;
	int cycleCoke = A * t;

	if (K % cycleCoke == 0) {
		return K / cycleCoke * cycleTime - s;
	} else {
		int leftCoke = K % cycleCoke;
		return K / cycleCoke * cycleTime + leftCoke / A;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K >> A;

	for (int i = 0; i < N; i++) {
		cin >> t >> s;

		int drinkTime = GetTime();
		if (drinkTime < minTime) {
			minTime = drinkTime;
		}
	}

	cout << minTime << "\n";

	return 0;
}