#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> A, B;

int GetCountOfFood(int predator, vector<int> &foods)
{
	int begin = 0;
	int end = foods.size() - 1;
	int ret = 0;

	while (begin <= end) {
		int mid = (begin + end) / 2;

		if (foods[mid] < predator) {
			begin = mid + 1;
			ret = mid + 1;
		} else {
			end = mid - 1;
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		A = vector<int>(N);
		B = vector<int>(M);

		for (int j = 0; j < N; j++) {
			cin >> A[j];
		}
		for (int j = 0; j < M; j++) {
			cin >> B[j];
		}

		sort(B.begin(), B.end(), less<int>());

		int count = 0;
		for (int j = 0; j < N; j++) {
			count += GetCountOfFood(A[j], B);
		}

		cout << count << "\n";
	}

	return 0;
}