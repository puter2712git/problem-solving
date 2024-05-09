#include <iostream>
#include <vector>

#define LOTTO_NUMBER_LENGTH 6

using namespace std;

int k;
vector<int> S;
int lottoNums[LOTTO_NUMBER_LENGTH];

void PrintAllSets(int startIndex, int currIndex)
{
	if (currIndex == LOTTO_NUMBER_LENGTH) {
		for (int i = 0; i < LOTTO_NUMBER_LENGTH; ++i) {
			cout << lottoNums[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = startIndex; i < k; ++i) {
		lottoNums[currIndex] = S[i];
		PrintAllSets(i + 1, currIndex + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (true) {
		cin >> k;
		if (k == 0)
			break;

		S = vector<int>(k);
		for (int i = 0; i < k; ++i) {
			cin >> S[i];
		}

		PrintAllSets(0, 0);
		cout << "\n";
	}

	return 0;
}