#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Tile
{
	char type;
	bool isVisited;
};

const pair<int, int> DIRECTIONS[4] = {
	{ -1, 0 },
	{ 1, 0 },
	{ 0, -1 },
	{ 0, 1 },
};

int N, M;
vector<vector<Tile>> tiles;

int FindPerson(pair<int, int> &startPos)
{
	int ret = 0;

	stack<pair<int, int>> s;
	s.push(startPos);
	tiles[startPos.first][startPos.second].isVisited = true;

	while (!s.empty()) {
		pair<int, int> currPos = s.top();
		s.pop();

		for (const auto &dir : DIRECTIONS) {
			int row = currPos.first + dir.first;
			int column = currPos.second + dir.second;

			if (row < 0 || row >= N || column < 0 || column >= M)
				continue;
			if (tiles[row][column].isVisited || tiles[row][column].type == 'X')
				continue;

			tiles[row][column].isVisited = true;
			if (tiles[row][column].type == 'P')
				ret++;

			s.push({ row, column });
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	pair<int, int> initPosition;

	cin >> N >> M;
	tiles = vector<vector<Tile>>(N, vector<Tile>(M, Tile{ 'O', false }));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tiles[i][j].type;

			if (tiles[i][j].type == 'I') {
				initPosition = { i, j };
			}
		}
	}

	int personCount = FindPerson(initPosition);
	if (personCount == 0) {
		cout << "TT\n";
	} else {
		cout << personCount << "\n";
	}

	return 0;
}
