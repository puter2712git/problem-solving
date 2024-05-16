#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> maze;
vector<vector<int>> record;

void Fill()
{
	record[1][1] = maze[1][1];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			record[i][j] = maze[i][j] + max(record[i - 1][j], max(record[i][j - 1], record[i - 1][j - 1]));
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	maze = vector<vector<int>>(N + 1, vector<int>(M + 1));
	record = vector<vector<int>>(N + 1, vector<int>(M + 1, 0));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> maze[i][j];
		}
	}

	Fill();
	cout << record[N][M] << "\n";

	return 0;
}