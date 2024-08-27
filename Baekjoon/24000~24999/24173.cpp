#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int A, K;
vector<int> arr;

int swapCount;

void heapify(vector<int> &arr, int k, int n)
{
	int left = 2 * k;
	int right = 2 * k + 1;
	int smaller = -1;

	if (right <= n) {
		if (arr[left] < arr[right]) {
			smaller = left;
		} else {
			smaller = right;
		}
	} else if (left <= n) {
		smaller = left;
	} else {
		return;
	}

	if (arr[smaller] < arr[k]) {
		swap(arr[k], arr[smaller]);

		swapCount++;
		if (swapCount == K) {
			cout << arr[k] << " " << arr[smaller] << "\n";
		}

		heapify(arr, smaller, n);
	}
}

void build_min_heap(vector<int> &arr, int n)
{
	for (int i = floor(n / 2); i > 0; i--) {
		heapify(arr, i, n);
	}
}

void heap_sort(vector<int> &arr)
{
	build_min_heap(arr, A);
	for (int i = A; i > 1; i--) {
		swap(arr[1], arr[i]);

		swapCount++;
		if (swapCount == K) {
			if (arr[1] < arr[i]) {
				cout << arr[1] << " " << arr[i] << "\n";
			} else {
				cout << arr[i] << " " << arr[1] << "\n";
			}
		}

		heapify(arr, 1, i - 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> A >> K;
	arr = vector<int>(A + 1);

	for (int i = 1; i <= A; i++) {
		cin >> arr[i];
	}

	heap_sort(arr);
	if (swapCount < K) {
		cout << "-1\n";
	}

	return 0;
}