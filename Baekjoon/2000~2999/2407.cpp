/**
 * 2407 백준 조합
 *
 * 조합을 구하는 문제
 * nCm = n-1Cm-1 + n-1Cm 공식을 이용한다.
 * 순수 재귀만을 이용하면 시간이 오래 걸리므로
 * Dynamic Programming을 이용한다.
 *
 * int 범위를 벗어나므로 python을 사용했다.
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> combinations;

long long GetCombination(int n, int m)
{
	combinations[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				combinations[i][j] = 1;
			} else {
				combinations[i][j] =
				    combinations[i - 1][j - 1] + combinations[i - 1][j];
			}
		}
	}

	return combinations[n][m];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	int m;

	cin >> n >> m;
	combinations = vector<vector<long long>>(n + 1, vector<long long>(n + 1));

	cout << GetCombination(n, m) << "\n";

	return 0;
}