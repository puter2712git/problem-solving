#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N;
int K;
vector<vector<int>> table;
string directions[4] = { "down", "right", "up", "left" };
int dirIndex = 0;

map<int, pair<int, int>> records;

pair<int, int> GetNextPosition(int i, int j)
{
	string dir = directions[dirIndex];
	pair<int, int> ret;

	if (dir == "down") {
		ret = { i + 1, j };
	} else if (dir == "right") {
		ret = { i, j + 1 };
	} else if (dir == "up") {
		ret = { i - 1, j };
	} else if (dir == "left") {
		ret = { i, j - 1 };
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	cin >> K;
	table = vector<vector<int>>(N, vector<int>(N, -1));

	int i = 0;
	int j = 0;
	int num = N * N;
	while (num > 0) {
		table[i][j] = num;
		records.insert({ num, { i, j } });
		pair<int, int> pos = GetNextPosition(i, j);

		if (pos.first < 0 || pos.first > N - 1 || pos.second < 0 || pos.second > N - 1 ||
		    table[pos.first][pos.second] != -1) {
			dirIndex = (dirIndex + 1) % 4;
		}

		pos = GetNextPosition(i, j);
		i = pos.first;
		j = pos.second;

		--num;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << table[i][j] << " ";
		}
		cout << "\n";
	}
	cout << records[K].first + 1 << " " << records[K].second + 1 << "\n";

	return 0;
}