#include <iostream>
#include <vector>

using namespace std;

int T;
int N;
vector<int> nums;
vector<bool> isVisited;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		nums = vector<int>(N + 1);
		isVisited = vector<bool>(N + 1, false);

		for (int j = 1; j <= N; j++) {
			cin >> nums[j];
		}

		int count = 0;

		for (int j = 1; j <= N; j++) {
			if (isVisited[j])
				continue;
			int curr = nums[j];
			isVisited[j] = true;

			while (!isVisited[curr]) {
				isVisited[curr] = true;
				curr = nums[curr];
			}

			count++;
		}

		cout << count << "\n";
	}

	return 0;
}