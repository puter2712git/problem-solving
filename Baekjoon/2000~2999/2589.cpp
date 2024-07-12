#define INF 123'456'789

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

struct Point
{
	int row;
	int column;
};

struct Tile
{
	char type;
};

const vector<Point> DIRECTIONS = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

int rowLength, columnLength;
vector<vector<Tile>> tiles;
vector<vector<bool>> visitFlags;

int GetMaxDistance(int row, int column)
{
	int ret = 0;

	queue<pair<Point, int>> q;
	q.push(make_pair(Point{ row, column }, 0));
	visitFlags[row][column] = true;

	while (!q.empty()) {
		pair<Point, int> curr = q.front();
		Point currPoint = curr.first;
		int currDistance = curr.second;
		q.pop();

		Tile &currTile = tiles[currPoint.row][currPoint.column];

		ret = max(ret, currDistance);

		for (const auto &dir : DIRECTIONS) {
			int nextRow = currPoint.row + dir.row;
			int nextColumn = currPoint.column + dir.column;

			if (nextRow < 0 || nextRow >= rowLength || nextColumn < 0 || nextColumn >= columnLength)
				continue;

			Tile &nextTile = tiles[nextRow][nextColumn];
			if (visitFlags[nextRow][nextColumn] || nextTile.type == 'W')
				continue;

			visitFlags[nextRow][nextColumn] = true;
			q.push(make_pair(Point{ nextRow, nextColumn }, currDistance + 1));
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> rowLength >> columnLength;
	tiles = vector<vector<Tile>>(rowLength, vector<Tile>(columnLength, { '\0' }));

	for (int i = 0; i < rowLength; i++) {
		for (int j = 0; j < columnLength; j++) {
			cin >> tiles[i][j].type;
		}
	}

	int maxDist = 0;
	for (int i = 0; i < rowLength; i++) {
		for (int j = 0; j < columnLength; j++) {
			if (tiles[i][j].type == 'W')
				continue;

			visitFlags = vector<vector<bool>>(rowLength, vector<bool>(columnLength, false));
			maxDist = max(maxDist, GetMaxDistance(i, j));
		}
	}

	cout << maxDist << "\n";

	return 0;
}