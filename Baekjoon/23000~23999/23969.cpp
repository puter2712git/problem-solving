#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> A;

int swapCount;

void BubbleSort(vector<int> &arr)
{
	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (A[j] > A[j + 1]) {
				swap(A[j], A[j + 1]);
				swapCount++;

				if (swapCount == K) {
					for (int &element : A) {
						cout << element << " ";
					}
					cout << "\n";
					return;
				}
			}
		}
	}

	cout << "-1\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;
	A = vector<int>(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	BubbleSort(A);

	return 0;
}