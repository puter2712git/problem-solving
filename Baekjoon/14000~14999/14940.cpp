#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const pair<int, int> DIRECTIONS[4] = {
	{ -1, 0 },
	{ 1, 0 },
	{ 0, -1 },
	{ 0, 1 },
};

struct Tile
{
	int type;
	int distance;
	bool isVisited;
};

int n, m;
vector<vector<Tile>> field;
pair<int, int> target;

void SetDistancesOfField()
{
	queue<pair<int, int>> q;
	q.push(target);
	field[target.first][target.second].isVisited = true;
	field[target.first][target.second].distance = 0;

	while (!q.empty()) {
		pair<int, int> currPoint = q.front();
		q.pop();

		for (const auto &dir : DIRECTIONS) {
			int row = currPoint.first + dir.first;
			int column = currPoint.second + dir.second;

			if (row < 0 || row >= n || column < 0 || column >= m)
				continue;
			if (field[row][column].isVisited || field[row][column].type == 0)
				continue;

			field[row][column].distance = field[currPoint.first][currPoint.second].distance + 1;
			field[row][column].isVisited = true;

			q.push({ row, column });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	field = vector<vector<Tile>>(n, vector<Tile>(m, Tile{ 0, -1, false }));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> field[i][j].type;

			if (field[i][j].type == 0) {
				field[i][j].distance = 0;
			} else if (field[i][j].type == 1) {
				field[i][j].distance = -1;
			} else if (field[i][j].type == 2) {
				target = { i, j };
			}
		}
	}

	SetDistancesOfField();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << field[i][j].distance << " ";
		}
		cout << "\n";
	}
}