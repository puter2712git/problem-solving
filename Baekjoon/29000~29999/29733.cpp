#include <iostream>
#include <string>

using namespace std;

const int dx[3] = { -1, 0, 1 };
const int dy[3] = { -1, 0, 1 };
const int dz[3] = { -1, 0, 1 };

int R, C, H;
char cube[100][100][100];
char result[100][100][100];

int GetAdjacentMineCount(int r, int c, int h)
{
	int ret = 0;

	for (int x : dx) {
		for (int y : dy) {
			for (int z : dz) {
				if (x == 0 && y == 0 && z == 0)
					continue;

				int row = r - x;
				int column = c - y;
				int height = h - z;
				if (row < 0 || row >= R || column < 0 || column >= C || height < 0 || height >= H)
					continue;

				if (cube[column][row][height] == '*')
					ret++;
			}
		}
	}

	return ret;
}

void Fill()
{
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				if (cube[k][j][i] == '*') {
					result[k][j][i] = '*';
					continue;
				}

				int mineCount = GetAdjacentMineCount(j, k, i);
				result[k][j][i] = (mineCount % 10) + '0';
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> R >> C >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				cin >> cube[k][j][i];
			}
		}
	}

	Fill();

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				cout << result[k][j][i];
			}
			cout << "\n";
		}
	}

	return 0;
}