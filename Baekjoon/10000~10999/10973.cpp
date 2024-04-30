#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> arr;

int GetSwapPoint()
{
	for (int i = N - 1; i >= 0; --i) {
		if (arr[i] < arr[i - 1]) {
			return i - 1;
		}
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	arr = vector<int>(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int swapIndex = GetSwapPoint();
	if (swapIndex == -1) {
		cout << -1 << "\n";
		return 0;
	}

	for (int i = N - 1; i > swapIndex; --i) {
		if (arr[i] < arr[swapIndex]) {
			swap(arr[i], arr[swapIndex]);
			sort(arr.begin() + swapIndex + 1, arr.end(), greater<int>());
			break;
		}
	}

	for (int i = 0; i < N; ++i) {
		cout << arr[i] << " ";
	}
	cout << "\n";

	return 0;
}