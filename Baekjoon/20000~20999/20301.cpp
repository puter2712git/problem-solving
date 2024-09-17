#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int N, K, M;
deque<int> dq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K >> M;
	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}

	vector<int> sequence;
	int popCount = 0;
	int removeCount = 0;
	bool isReversed = false;

	while (!dq.empty()) {

		if ((!isReversed && popCount == K - 1) || (isReversed && popCount == K)) {
			popCount = 0;
			removeCount++;

			sequence.push_back(dq.front());
			dq.pop_front();

			if (removeCount == M) {
				removeCount = 0;
				isReversed = !isReversed;
			}
			continue;
		}

		if (isReversed) {
			int tmp = dq.back();
			dq.pop_back();
			dq.push_front(tmp);
		} else {
			int tmp = dq.front();
			dq.pop_front();
			dq.push_back(tmp);
		}
		popCount++;
	}

	for (int &element : sequence) {
		cout << element << "\n";
	}

	return 0;
}