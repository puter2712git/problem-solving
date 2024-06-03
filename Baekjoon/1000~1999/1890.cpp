#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Tile
{
	int jumpDistance;
	long long visitCount;
};

int N;
vector<vector<Tile>> board;

void Fill()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Tile curr = board[i][j];
			int jump = curr.jumpDistance;

			if (jump == 0)
				continue;

			// 오른쪽
			if (j + jump < N) {
				board[i][j + jump].visitCount += curr.visitCount;
			}

			// 아래
			if (i + jump < N) {
				board[i + jump][j].visitCount += curr.visitCount;
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
	board = vector<vector<Tile>>(N, vector<Tile>(N, Tile{ -1, 0 }));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j].jumpDistance;
		}
	}
	board[0][0].visitCount = 1;

	Fill();
	cout << board[N - 1][N - 1].visitCount << "\n";

	return 0;
}