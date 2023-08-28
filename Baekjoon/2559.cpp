#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> temperatures;

int sum;
vector<int> partial_sums;

vector<int> target_sums;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		temperatures.push_back(tmp);

		sum += tmp;
		partial_sums.push_back(sum);
	}

	for (int i = K - 1; i < N; i++) {
		target_sums.push_back(i == K - 1 ? partial_sums[i] : partial_sums[i] - partial_sums[i - K]);
	}

	cout << *max_element(target_sums.begin(), target_sums.end()) << "\n";

	return 0;
}