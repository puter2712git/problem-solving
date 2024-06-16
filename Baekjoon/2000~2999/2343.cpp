#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> blurays;
int maxBluray, sumOfBlurays;

int GetMinSizeBluray()
{
	int begin = maxBluray;
	int end = sumOfBlurays;

	while (begin <= end) {
		int mid = (begin + end) / 2;

		int currSum = 0;
		int currCount = 0;

		for (int i = 0; i < N; i++) {
			if (currSum + blurays[i] > mid) {
				currSum = 0;
				currCount++;
			}
			currSum += blurays[i];
		}
		if (currSum > 0)
			currCount++;

		if (currCount > M)
			begin = mid + 1;
		else
			end = mid - 1;
	}

	return begin;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	blurays = vector<int>(N);
	for (int i = 0; i < N; i++) {
		cin >> blurays[i];

		maxBluray = max(maxBluray, blurays[i]);
		sumOfBlurays += blurays[i];
	}

	cout << GetMinSizeBluray() << "\n";

	return 0;
}