#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Tile
{
	bool hasTrash;
	bool isVisited;
};

const pair<int, int> directions[4] = {
	{ -1, 0 },
	{ 1, 0 },
	{ 0, -1 },
	{ 0, 1 },
};

int N, M;
int K;
vector<vector<Tile>> tiles;

int GetMaxTrashSize()
{
	int ret = -1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			Tile currTile = tiles[i][j];
			if (!currTile.hasTrash || currTile.isVisited)
				continue;

			stack<pair<int, int>> s;
			int trashSize = 0;

			s.push({ i, j });
			tiles[i][j].isVisited = true;

			while (!s.empty()) {
				pair<int, int> currPoint = s.top();
				s.pop();
				trashSize++;

				for (const auto &dir : directions) {
					int row = currPoint.first + dir.first;
					int column = currPoint.second + dir.second;

					if (row < 1 || row > N || column < 1 || column > M)
						continue;
					if (!tiles[row][column].hasTrash || tiles[row][column].isVisited)
						continue;

					s.push({ row, column });
					tiles[row][column].isVisited = true;
				}
			}

			ret = max(ret, trashSize);
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> K;
	tiles = vector<vector<Tile>>(N + 1, vector<Tile>(M + 1, Tile{ false, false }));
	for (int i = 0; i < K; i++) {
		int r, c;
		cin >> r >> c;
		tiles[r][c].hasTrash = true;
	}

	cout << GetMaxTrashSize() << "\n";

	return 0;
}