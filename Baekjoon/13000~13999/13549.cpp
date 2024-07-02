#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, K;
int maxSize;
vector<bool> visitFlags;

int GetMinTime()
{
	int ret = -1;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, N });

	while (!pq.empty()) {
		pair<int, int> curr = pq.top();
		pq.pop();

		int currTime = curr.first;
		int currPos = curr.second;

		visitFlags[currPos] = true;

		if (currPos == K) {
			ret = currTime;
			break;
		}

		if (currPos - 1 >= 0 && !visitFlags[currPos - 1]) {
			pq.push({ currTime + 1, currPos - 1 });
		}
		if (currPos + 1 <= maxSize && !visitFlags[currPos + 1]) {
			pq.push({ currTime + 1, currPos + 1 });
		}
		if (currPos * 2 <= 100'000 * 2 && !visitFlags[currPos * 2]) {
			pq.push({ currTime, currPos * 2 });
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;
	maxSize = max(N, K);
	visitFlags = vector<bool>(100'000 * 2, false);

	cout << GetMinTime() << "\n";

	return 0;
}