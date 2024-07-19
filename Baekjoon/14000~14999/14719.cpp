#include <iostream>
#include <vector>

using namespace std;

int H, W;
vector<int> world;

int GetWaterSize()
{
	int ret = 0;

	for (int i = 1; i < W - 1; i++) {
		int maxLeft = 0;
		int maxRight = 0;

		for (int j = 0; j < i; j++) {
			maxLeft = max(maxLeft, world[j]);
		}
		for (int j = i + 1; j < W; j++) {
			maxRight = max(maxRight, world[j]);
		}

		ret += max(0, min(maxLeft, maxRight) - world[i]);
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> H >> W;
	world = vector<int>(W);

	for (int i = 0; i < W; i++) {
		cin >> world[i];
	}

	cout << GetWaterSize() << "\n";

	return 0;
}