#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> A;
vector<bool> visitFlags;
int maxSum = -1;

void Trace(int currLen, int currSum, int lastIndex)
{
	if (currLen == N) {
		if (maxSum == -1 || maxSum < currSum) {
			maxSum = currSum;
		}
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visitFlags[i])
			continue;

		visitFlags[i] = true;

		if (lastIndex != -1) {
			Trace(currLen + 1, currSum + abs(A[i] - A[lastIndex]), i);
		} else {
			Trace(currLen + 1, currSum, i);
		}
		visitFlags[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	A = vector<int>(N);
	visitFlags = vector<bool>(N, false);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	Trace(0, 0, -1);
	cout << maxSum << "\n";

	return 0;
}