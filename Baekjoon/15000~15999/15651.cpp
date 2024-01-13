#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> nums;
vector<int> permutation(7);

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
		permutation[depth] = nums[i];
		print_permutations(depth + 1);
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		nums.push_back(i);
	}

	print_permutations(0);

	return 0;
}