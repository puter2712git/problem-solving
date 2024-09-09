#include <iostream>
#include <vector>

using namespace std;

int T;
vector<vector<char>> board;
char curr;

bool IsWin()
{
	bool ret = false;

	ret = ret || (board[0][0] == curr && board[0][1] == curr && board[0][2] == curr);
	ret = ret || (board[1][0] == curr && board[1][1] == curr && board[1][2] == curr);
	ret = ret || (board[2][0] == curr && board[2][1] == curr && board[2][2] == curr);
	ret = ret || (board[0][0] == curr && board[1][0] == curr && board[2][0] == curr);
	ret = ret || (board[0][1] == curr && board[1][1] == curr && board[2][1] == curr);
	ret = ret || (board[0][2] == curr && board[1][2] == curr && board[2][2] == curr);
	ret = ret || (board[0][0] == curr && board[1][1] == curr && board[2][2] == curr);
	ret = ret || (board[2][0] == curr && board[1][1] == curr && board[0][2] == curr);

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;

	for (int t = 0; t < T; t++) {
		board = vector<vector<char>>(3, vector<char>(3));

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> board[i][j];
			}
		}
		cin >> curr;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board[i][j] != '-')
					continue;

				board[i][j] = curr;

				if (IsWin()) {
					goto WIN;
				}

				board[i][j] = '-';
			}
		}

		continue;

	WIN:
		cout << "Case " << t + 1 << ":\n";
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << board[i][j];
			}
			cout << "\n";
		}
	}

	return 0;
}