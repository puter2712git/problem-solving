#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Tile
{
	int order;
	bool isVisited;
};

int T;
int l;
vector<vector<Tile>> board;

const pair<int, int> directions[8] = {
	{ 1, -2 },
	{ 2, -1 },
	{ 2, 1 },
	{ 1, 2 },
	{ -1, 2 },
	{ -2, 1 },
	{ -2, -1 },
	{ -1, -2 },
};

int GetMoveCount(pair<int, int> &begin, pair<int, int> &end)
{
	queue<pair<int, int>> q;
	q.push(begin);
	board[begin.first][begin.second] = { 0, false };

	while (!q.empty()) {
		pair<int, int> curr = q.front();
		q.pop();

		if (curr == end)
			break;

		for (int i = 0; i < 8; i++) {
			pair<int, int> currDir = directions[i];
			int row = curr.first + currDir.first;
			int column = curr.second + currDir.second;

			if (row < 0 || row >= l || column < 0 || column >= l)
				continue;
			if (board[row][column].isVisited)
				continue;

			board[row][column] = { board[curr.first][curr.second].order + 1, true };
			q.push({ row, column });
		}
	}

	return board[end.first][end.second].order;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> l;
		board.clear();
		board = vector<vector<Tile>>(l, vector<Tile>(l, Tile{ 0, false }));

		pair<int, int> begin, end;
		cin >> begin.first >> begin.second;
		cin >> end.first >> end.second;

		cout << GetMoveCount(begin, end) << "\n";
	}

	return 0;
}