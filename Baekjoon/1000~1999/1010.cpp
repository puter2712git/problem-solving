#include <iostream>
#include <vector>

using namespace std;

int combination(int a, int b)
{
	if (a == b || b == 0) return 1;

	return combination(a - 1, b - 1) + combination(a - 1, b);
}

vector<vector<int>> get_combinations(int range)
{
	vector<vector<int>> ret;

	for (int i = 0; i < range; i++) {
		ret.push_back(vector<int>());

		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				ret[i].push_back(1);
				continue;
			}

			if (i == j) {
				ret[i].push_back(1);
				continue;
			}

			ret[i].push_back(ret[i - 1][j - 1] + ret[i - 1][j]);
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	int N, M;

	vector<vector<int>> combs = get_combinations(31);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;

		cout << combs[M][N] << "\n";
	}

	return 0;
}