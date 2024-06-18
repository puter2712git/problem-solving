#include <iostream>
#include <queue>
#include <vector>

#define BOARD_SIZE 100

using namespace std;

struct Tile
{
	int rollCount;
	bool isVisited;
	int connection;
};

int N, M;
vector<Tile> board;

int GetMinRollCount()
{
	queue<int> q;
	q.push(1);
	board[1].isVisited = true;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		if (curr == 100)
			break;

		for (int i = 1; i <= 6; i++) {
			int nextPos = curr + i;
			if (nextPos > 100)
				continue;

			while (board[nextPos].connection != -1) {
				nextPos = board[nextPos].connection;
			}

			if (board[nextPos].isVisited)
				continue;

			board[nextPos].rollCount = board[curr].rollCount + 1;
			board[nextPos].isVisited = true;
			q.push(nextPos);
		}
	}

	return board[100].rollCount;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	board = vector<Tile>(BOARD_SIZE + 1, Tile{ 0, false, -1 });
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		board[x].connection = y;
	}
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		board[u].connection = v;
	}

	cout << GetMinRollCount() << "\n";

	return 0;
}