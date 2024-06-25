#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

struct Point
{
	int row;
	int column;
};

struct Tile
{
	int type;
	bool isVisited;
};

int N, M;
vector<vector<Tile>> city;
vector<Point> housePoses;
vector<Point> chickenPoses;

int GetChickenDistanceWithCombination(vector<int> &indices)
{
	int ret = 0;

	for (const auto &housePos : housePoses) {
		int minDist = numeric_limits<int>::max();

		for (int i = 0; i < chickenPoses.size(); i++) {
			if (indices[i] == 1)
				continue;
			minDist =
			    min(minDist, abs(housePos.row - chickenPoses[i].row) + abs(housePos.column - chickenPoses[i].column));
		}
		ret += minDist;
	}

	return ret;
}

int GetMinCityChickenDistance()
{
	int ret = numeric_limits<int>::max();

	vector<int> indices;
	for (int i = 0; i < chickenPoses.size(); i++) {
		if (i < M) {
			indices.push_back(0);
		} else {
			indices.push_back(1);
		}
	}

	do {
		ret = min(ret, GetChickenDistanceWithCombination(indices));
	} while (next_permutation(indices.begin(), indices.end()));

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	city = vector<vector<Tile>>(N, vector<Tile>(N, Tile{ 0, false }));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> city[i][j].type;

			if (city[i][j].type == 1) {
				housePoses.push_back(Point{ i, j });
			} else if (city[i][j].type == 2) {
				chickenPoses.push_back(Point{ i, j });
			}
		}
	}

	cout << GetMinCityChickenDistance() << "\n";

	return 0;
}