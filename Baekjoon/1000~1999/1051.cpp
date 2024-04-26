#include <iostream>
#include <vector>

using namespace std;

int N;
int M;
vector<vector<int>> rect;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	rect = vector<vector<int>>(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char tmp;
			cin >> tmp;
			rect[i][j] = tmp - '0';
		}
	}

	int maxSquareSize = min(N, M);

	while (maxSquareSize) {
		for (int i = 0; i < N - maxSquareSize + 1; i++) {
			for (int j = 0; j < M - maxSquareSize + 1; j++) {
				int curr = rect[i][j];

				if (curr == rect[i][j + maxSquareSize - 1] &&
				    curr == rect[i + maxSquareSize - 1][j] &&
				    curr ==
				        rect[i + maxSquareSize - 1][j + maxSquareSize - 1]) {
					cout << maxSquareSize * maxSquareSize << "\n";
					return 0;
				}
			}
		}

		maxSquareSize--;
	}

	cout << 1 << "\n";

	return 0;
}