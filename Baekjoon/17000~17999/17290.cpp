#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const pair<int, int> directions[4] = {
	{ -1, 0 },
	{ 1, 0 },
	{ 0, -1 },
	{ 0, 1 },
};

struct Tile
{
	char state;
	bool isSafe;
	bool isVisited;
};

int r, c;
vector<vector<Tile>> board;

void Update(int row, int column)
{
	for (int i = 1; i <= 10; i++) {
		board[i][column].isSafe = false;
	}

	for (int i = 1; i <= 10; i++) {
		board[row][i].isSafe = false;
	}
}

pair<int, int> FindSafePoint()
{
	queue<pair<int, int>> q;
	q.push({ r, c });
	board[r][c].isVisited = true;

	pair<int, int> ret = { -1, -1 };

	while (!q.empty()) {
		pair<int, int> curr = q.front();
		q.pop();

		if (board[curr.first][curr.second].isSafe) {
			ret = { curr.first, curr.second };
			break;
		}

		for (const auto &dir : directions) {
			int row = curr.first + dir.first;
			int column = curr.second + dir.second;

			if (row < 1 || row > 10 || column < 1 || column > 10)
				continue;
			if (board[row][column].isVisited)
				continue;

			board[row][column].isVisited = true;
			q.push({ row, column });
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	board = vector<vector<Tile>>(11, vector<Tile>(11, Tile{ 'x', true, false }));

	cin >> r >> c;
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			cin >> board[i][j].state;
		}
	}

	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			if (board[i][j].state == 'o') {
				Update(i, j);
			}
		}
	}

	pair<int, int> safePoint = FindSafePoint();
	int distance = abs(safePoint.first - r) + abs(safePoint.second - c);

	cout << distance << "\n";

	return 0;
}