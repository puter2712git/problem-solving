#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<pair<int, bool>> nums;
vector<int> permutation(8);

void print_permutations(int depth)
{
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << permutation[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = 0; i < nums.size(); i++) {
		if (nums[i].second) continue;
		if (depth > 0 && permutation[depth - 1] >= nums[i].first) continue;

		nums[i].second = true;
		permutation[depth] = nums[i].first;
		print_permutations(depth + 1);
		nums[i].second = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		nums.push_back({ i, false });
	}
	print_permutations(0);

	return 0;
}