#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Point
{
	int x;
	int y;
};

struct Tile
{
	int num;
	bool isVisited;
};

const Point DIRECTIONS[4] = {
	Point{ -1, 0 },
	Point{ 1, 0 },
	Point{ 0, -1 },
	Point{ 0, 1 },
};

int N, M;
vector<vector<Tile>> paper;

int maxSum;

void Trace(Point &currPoint, int currLen = 0, int currSum = 0)
{
	if (currLen == 4) {
		maxSum = max(maxSum, currSum);
		return;
	}

	for (const auto &dir : DIRECTIONS) {
		Point p = Point{ currPoint.x + dir.x, currPoint.y + dir.y };
		if (p.x < 0 || p.x >= N || p.y < 0 || p.y >= M)
			continue;
		if (paper[p.x][p.y].isVisited)
			continue;

		paper[p.x][p.y].isVisited = true;
		Trace(p, currLen + 1, currSum + paper[p.x][p.y].num);
		paper[p.x][p.y].isVisited = false;
	}
}

void Check(Point &currPoint)
{
	int tmp;
	int x = currPoint.x;
	int y = currPoint.y;

	// 'ㅏ'
	if (x < N - 1 && y < M - 2) {
		tmp = paper[x][y].num + paper[x][y + 1].num + paper[x + 1][y + 1].num + paper[x][y + 2].num;
		maxSum = max(maxSum, tmp);
	}

	// 'ㅗ'
	if (x < N - 2 && y > 0) {
		tmp = paper[x][y].num + paper[x + 1][y].num + paper[x + 1][y - 1].num + paper[x + 2][y].num;
		maxSum = max(maxSum, tmp);
	}

	// 'ㅓ'
	if (x > 0 && y < M - 2) {
		tmp = paper[x][y].num + paper[x][y + 1].num + paper[x - 1][y + 1].num + paper[x][y + 2].num;
		maxSum = max(maxSum, tmp);
	}

	// 'ㅜ'
	if (x < N - 2 && y < M - 1) {
		tmp = paper[x][y].num + paper[x + 1][y].num + paper[x + 1][y + 1].num + paper[x + 2][y].num;
		maxSum = max(maxSum, tmp);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	paper = vector<vector<Tile>>(N, vector<Tile>(M, Tile{ -1, false }));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> paper[i][j].num;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			Point p = Point{ i, j };
			paper[i][j].isVisited = true;
			Trace(p, 1, paper[i][j].num);
			paper[i][j].isVisited = false;

			Check(p);
		}
	}

	cout << maxSum << "\n";

	return 0;
}