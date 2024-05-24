#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> boxes;
vector<int> memo;

void Fill()
{
	for (int i = 0; i < n; i++) {
		memo[i] = 1;
		for (int j = 0; j < i; j++) {
			if (boxes[i] > boxes[j] && memo[i] < memo[j] + 1) {
				memo[i] = memo[j] + 1;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	boxes = vector<int>(n, 1);
	memo = vector<int>(n);

	for (int i = 0; i < n; i++) {
		cin >> boxes[i];
	}

	Fill();

	cout << *max_element(memo.begin(), memo.end()) << "\n";

	return 0;
}