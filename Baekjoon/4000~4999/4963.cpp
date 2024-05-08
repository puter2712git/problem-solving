#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	short type;
	bool isVisited;
};

const pair<int, int> directions[8] = { { -1, -1 }, { 0, -1 }, { 1, -1 }, { 1, 0 }, { 1, 1 }, { 0, 1 }, { -1, 1 },
	{ -1, 0 } };

int w, h;
vector<vector<Node>> world;

void Dfs(int row, int column)
{
	world[row][column].isVisited = true;

	for (int i = 0; i < 8; ++i) {
		pair<int, int> dir = directions[i];
		int x = column + dir.second;
		int y = row + dir.first;

		if (x < 0 || x >= w || y < 0 || y >= h)
			continue;

		if (world[y][x].type == 1 && !world[y][x].isVisited) {
			world[y][x].isVisited = true;
			Dfs(y, x);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;

		world.clear();
		world = vector<vector<Node>>(h, vector<Node>(w, { 0, false }));

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				cin >> world[i][j].type;
			}
		}

		int countOfIsland = 0;

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (world[i][j].type == 1 && !world[i][j].isVisited) {
					++countOfIsland;
					Dfs(i, j);
				}
			}
		}

		cout << countOfIsland << "\n";
	}

	return 0;
}