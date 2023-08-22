#include <iostream>
#include <vector>

using namespace std;

struct Point {
	int x;
	int y;
};

vector<vector<int>> board(9, vector<int>(9));
vector<Point> zero_points;
bool isFound = false;

bool promising(int x, int y, int target)
{
	// 가로
	for (int i = 0; i < 9; i++) {
		if (board[y][i] == target) return false;
	}

	// 세로
	for (int i = 0; i < 9; i++) {
		if (board[i][x] == target) return false;
	}

	// 3 x 3
	int boxX = x / 3;
	int boxY = y / 3;

	for (int i = boxY * 3; i < boxY * 3 + 3; i++) {
		for (int j = boxX * 3; j < boxX * 3 + 3; j++) {
			if (board[i][j] == target) return false;
		}
	}

	return true;
}

void print_board() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}

void sudoku(int depth)
{
	if (isFound) return;
	if (depth == zero_points.size()) {
		print_board();
		isFound = true;
		return;
	}

	for (int i = depth; i < zero_points.size(); i++) {
		int x = zero_points[i].x;
		int y = zero_points[i].y;

		for (int j = 1; j <= 9; j++) {
			if (!promising(x, y, j)) continue;

			board[y][x] = j;
			sudoku(depth + 1);
			board[y][x] = 0;
		}

		return;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				zero_points.push_back({
					.x = j,
					.y = i,
				});
			}
		}
	}

	sudoku(0);

	return 0;
}