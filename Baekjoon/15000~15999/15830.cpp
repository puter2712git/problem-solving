#include <iostream>

using namespace std;

long double V, W, D;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> V >> W >> D;

	long double collisionCount = 0;
	long double collisionTime = W / V;
	long double fallDistance = 5.0 * collisionTime * collisionTime;

	while (fallDistance < D) {
		collisionCount++;
		collisionTime *= 1.25;
		fallDistance += 5.0 * collisionTime * collisionTime;
	}

	cout << collisionCount << "\n";

	return 0;
}