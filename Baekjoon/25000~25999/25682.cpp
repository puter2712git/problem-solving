#include <iostream>
#include <algorithm>

using namespace std;

int N, M, K;
char board[2001][2001];

int psums[2001][2001];
int max_count = INT32_MIN;
int min_count = INT32_MAX;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];

			if ((i + j) % 2 == 0) {
				psums[i][j] = psums[i - 1][j] + psums[i][j - 1] - psums[i - 1][j - 1] + (board[i][j] == 'B' ? 0 : 1);
			}
			else {
				psums[i][j] = psums[i - 1][j] + psums[i][j - 1] - psums[i - 1][j - 1] + (board[i][j] == 'W' ? 0 : 1);
			}
		}
	}

	for (int y = K; y <= N; y++) {
		for (int x = K; x <= M; x++) {
			max_count = max(psums[y][x] - psums[y - K][x] - psums[y][x - K] + psums[y - K][x - K], max_count);
			min_count = min(psums[y][x] - psums[y - K][x] - psums[y][x - K] + psums[y - K][x - K], min_count);
		}
	}

	int elements[] = { max_count, min_count, K * K - max_count, K * K - min_count };
	cout << *min_element(elements, elements + 4) << "\n";

	return 0;
}