#include <iostream>
#include <vector>

using namespace std;

int T;
vector<vector<int>> board(9, vector<int>(9));
vector<bool> check(9, false);

bool CheckRow(int col)
{
	check = vector<bool>(9, false);

	for (int i = 0; i < 9; i++) {
		if (check[board[i][col] - 1])
			return false;

		check[board[i][col] - 1] = true;
	}

	return true;
}

bool CheckColumn(int row)
{
	check = vector<bool>(9, false);

	for (int i = 0; i < 9; i++) {
		if (check[board[row][i] - 1])
			return false;

		check[board[row][i] - 1] = true;
	}

	return true;
}

bool CheckSquare(int row, int col)
{
	check = vector<bool>(9, false);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (check[board[row + i][col + j]])
				return false;

			check[board[row + i][col + j]] = true;
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;

	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 9; k++) {
				cin >> board[j][k];
			}
		}

		bool isCorrect = true;

		for (int j = 0; j < 9; j++) {
			isCorrect = isCorrect && CheckRow(j);
			isCorrect = isCorrect && CheckColumn(j);
		}
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				isCorrect = isCorrect && CheckSquare(j * 3, k * 3);
			}
		}

		if (isCorrect) {
			cout << "Case " << i + 1 << ": CORRECT\n";
		} else {
			cout << "Case " << i + 1 << ": INCORRECT\n";
		}
	}

	return 0;
}