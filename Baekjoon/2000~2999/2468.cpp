#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Tile
{
	int height;
	bool isVisited;
};

const pair<int, int> directions[4] = {
	{ -1, 0 },
	{ 1, 0 },
	{ 0, -1 },
	{ 0, 1 },
};

int N;
vector<vector<Tile>> tiles;

void Reset()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tiles[i][j].isVisited = false;
		}
	}
}

int GetCountOfSafeArea(int waterHeight)
{
	int ret = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (tiles[i][j].height <= waterHeight || tiles[i][j].isVisited)
				continue;

			ret++;

			stack<pair<int, int>> positions;
			positions.push({ i, j });
			tiles[i][j].isVisited = true;

			while (!positions.empty()) {
				pair<int, int> curr = positions.top();
				positions.pop();

				for (int k = 0; k < 4; k++) {
					pair<int, int> dir = directions[k];
					int row = curr.first + dir.first;
					int column = curr.second + dir.second;

					if (row < 0 || row >= N || column < 0 || column >= N)
						continue;
					if (tiles[row][column].height <= waterHeight || tiles[row][column].isVisited)
						continue;

					positions.push({ row, column });
					tiles[row][column].isVisited = true;
				}
			}
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
	tiles = vector<vector<Tile>>(N, vector<Tile>(N, Tile()));

	int maxTileHeight = -1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tiles[i][j].height;
			maxTileHeight = maxTileHeight < tiles[i][j].height ? tiles[i][j].height : maxTileHeight;
			tiles[i][j].isVisited = false;
		}
	}

	int maxCountOfSafeArea = 1;
	for (int i = 1; i <= maxTileHeight; i++) {
		Reset();
		int count = GetCountOfSafeArea(i);
		maxCountOfSafeArea = maxCountOfSafeArea < count ? count : maxCountOfSafeArea;
	}

	cout << maxCountOfSafeArea << "\n";

	return 0;
}