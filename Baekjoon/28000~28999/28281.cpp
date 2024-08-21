#include <iostream>
#include <vector>

using namespace std;

int N, X;
vector<int> A;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> X;
	A = vector<int>(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int minCost = 12345678;
	for (int i = 0; i < N - 1; i++) {
		int curr = A[i] + A[i + 1];
		minCost = min(minCost, curr);
	}

	cout << minCost * X << "\n";

	return 0;
}