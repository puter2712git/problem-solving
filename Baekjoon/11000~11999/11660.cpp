#include <iostream>

using namespace std;

int N, M;
int table[1025][1025];

int partial_sums[1025][1025];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> table[i][j];
			partial_sums[i][j] = partial_sums[i - 1][j] + partial_sums[i][j - 1] - partial_sums[i - 1][j - 1] + table[i][j];
		}
	}
	
	for (int i = 0; i < M; i++) {
		int x1, y1;
		int x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << partial_sums[x2][y2] - partial_sums[x1 - 1][y2] - partial_sums[x2][y1 - 1] + partial_sums[x1 - 1][y1 - 1] << "\n";
	}

	return 0;
}