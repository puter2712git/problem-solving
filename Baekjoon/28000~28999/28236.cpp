#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<int> distances;
int minDistance = 1 << 30;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> k;
	distances = vector<int>(k + 1);
	for (int i = 1; i <= k; i++) {
		int f, d;
		cin >> f >> d;

		int distance = (f - 1) + (m + 1 - d);
		distances[i] = distance;
		minDistance = min(minDistance, distance);
	}

	for (int i = 1; i <= k; i++) {
		if (distances[i] == minDistance) {
			cout << i << "\n";
			break;
		}
	}

	return 0;
}