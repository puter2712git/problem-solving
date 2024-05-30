#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Tile
{
	bool isBlocked;
	bool isVisited;
};

const pair<int, int> directions[4] = {
	{ -1, 0 },
	{ 1, 0 },
	{ 0, -1 },
	{ 0, 1 },
};

int M, N, K;
vector<vector<Tile>> paper;

vector<int> GetAreas()
{
	vector<int> ret;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (paper[i][j].isBlocked || paper[i][j].isVisited)
				continue;

			stack<pair<int, int>> s;
			s.push({ i, j });
			paper[i][j].isVisited = true;

			int area = 1;

			while (!s.empty()) {
				pair<int, int> curr = s.top();
				s.pop();

				for (pair<int, int> dir : directions) {
					int y = curr.first + dir.first;
					int x = curr.second + dir.second;

					if (y < 0 || y >= M || x < 0 || x >= N)
						continue;
					if (paper[y][x].isBlocked || paper[y][x].isVisited)
						continue;

					area++;
					paper[y][x].isVisited = true;
					s.push({ y, x });
				}
			}

			ret.push_back(area);
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> M >> N >> K;
	paper = vector<vector<Tile>>(M, vector<Tile>(N, Tile{ false, false }));

	while (K--) {
		int x, y, nx, ny;
		cin >> x >> y >> nx >> ny;

		for (int i = y; i < ny; i++) {
			for (int j = x; j < nx; j++) {
				paper[i][j].isBlocked = true;
			}
		}
	}

	vector<int> areas = GetAreas();
	sort(areas.begin(), areas.end(), less<int>());

	cout << areas.size() << "\n";
	for (int i = 0; i < areas.size(); i++) {
		cout << areas[i] << " ";
	}
	cout << "\n";

	return 0;
}