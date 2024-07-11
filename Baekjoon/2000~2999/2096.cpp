#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> maxDP(3, 0);
vector<int> minDP(3, 0);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	while (N--) {
		vector<int> tiles(3);
		for (int i = 0; i < 3; i++) {
			cin >> tiles[i];
		}

		vector<int> tmpArr(3);

		tmpArr = { maxDP[0], maxDP[1], maxDP[2] };
		maxDP[0] = max(tmpArr[0], tmpArr[1]) + tiles[0];
		maxDP[1] = max(max(tmpArr[0], tmpArr[1]), tmpArr[2]) + tiles[1];
		maxDP[2] = max(tmpArr[1], tmpArr[2]) + tiles[2];

		tmpArr = { minDP[0], minDP[1], minDP[2] };
		minDP[0] = min(tmpArr[0], tmpArr[1]) + tiles[0];
		minDP[1] = min(min(tmpArr[0], tmpArr[1]), tmpArr[2]) + tiles[1];
		minDP[2] = min(tmpArr[1], tmpArr[2]) + tiles[2];
	}

	cout << max(max(maxDP[0], maxDP[1]), maxDP[2]) << " " << min(min(minDP[0], minDP[1]), minDP[2]) << "\n";

	return 0;
}