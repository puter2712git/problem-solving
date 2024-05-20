#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<char>> board;

int GetCountOfCandies()
{
	int ret = 1;

	for (int i = 0; i < N; i++) {
		int count = 1;

		for (int j = 1; j < N; j++) {
			if (board[i][j] == board[i][j - 1]) {
				count++;
			} else {
				count = 1;
			}
			ret = max(ret, count);
		}

		count = 1;
		for (int j = 1; j < N; j++) {
			if (board[j][i] == board[j - 1][i]) {
				count++;
			} else {
				count = 1;
			}
			ret = max(ret, count);
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	board = vector<vector<char>>(N, vector<char>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	int maxCandyCount = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i < N - 1) {
				if (board[i][j] != board[i + 1][j]) {
					swap(board[i][j], board[i + 1][j]);
					maxCandyCount = max(maxCandyCount, GetCountOfCandies());
					swap(board[i][j], board[i + 1][j]);
				}
			}

			if (j < N - 1) {
				if (board[i][j] != board[i][j + 1]) {
					swap(board[i][j], board[i][j + 1]);
					maxCandyCount = max(maxCandyCount, GetCountOfCandies());
					swap(board[i][j], board[i][j + 1]);
				}
			}
		}
	}

	cout << maxCandyCount << "\n";

	return 0;
}