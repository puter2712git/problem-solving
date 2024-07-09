#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

struct Tile
{
	int type;
	int pipeCounts[3];
};

int N;
vector<vector<Tile>> tiles;

void Fill()
{
	tiles[0][1].pipeCounts[0] = 1;
	for (int i = 2; i < N; i++) {
		if (tiles[0][i].type == 1)
			continue;

		tiles[0][i].pipeCounts[0] = tiles[0][i - 1].pipeCounts[0];
	}

	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			if (tiles[i][j].type == 0 && tiles[i][j - 1].type == 0 && tiles[i - 1][j].type == 0)
				tiles[i][j].pipeCounts[2] =
				    accumulate(tiles[i - 1][j - 1].pipeCounts, tiles[i - 1][j - 1].pipeCounts + 3, 0);

			if (tiles[i][j].type == 0) {
				tiles[i][j].pipeCounts[0] = tiles[i][j - 1].pipeCounts[0] + tiles[i][j - 1].pipeCounts[2];
				tiles[i][j].pipeCounts[1] = tiles[i - 1][j].pipeCounts[1] + tiles[i - 1][j].pipeCounts[2];
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	tiles = vector<vector<Tile>>(N, vector<Tile>(N, { 0, { 0, 0, 0 } }));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tiles[i][j].type;
		}
	}

	Fill();

	cout << accumulate(tiles[N - 1][N - 1].pipeCounts, tiles[N - 1][N - 1].pipeCounts + 3, 0);

	return 0;
}