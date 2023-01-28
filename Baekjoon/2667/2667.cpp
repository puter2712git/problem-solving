#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_MAP_LENGTH 25

const pair<int, int> dir[4] = {
	{ -1,  0 },
	{  1,  0 },
	{  0, -1 },
	{  0,  1 },
};

int map_len;
string map[MAX_MAP_LENGTH];
bool visited[MAX_MAP_LENGTH][MAX_MAP_LENGTH] = { false, };
vector<int> nr_houses;
int cnt = 0;

void find_houses(int x, int y)
{
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i].first;
		int ny = y + dir[i].second;

		if (nx < 0 || nx >= map_len || ny < 0 || ny >= map_len || visited[ny][nx] || map[ny][nx] != '1')
			continue;

		visited[ny][nx] = true;
		cnt++;
		find_houses(nx, ny);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> map_len;
	for (int i = 0; i < map_len; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < map_len; i++) {
		for (int j = 0; j < map_len; j++) {
			if (!visited[i][j] && map[i][j] == '1') {
				visited[i][j] = true;
				cnt++;
				find_houses(j, i);
				nr_houses.push_back(cnt);
				cnt = 0;
			}
		}
	}

	sort(nr_houses.begin(), nr_houses.end());

	cout << nr_houses.size() << '\n';
	for (int i = 0; i < nr_houses.size(); i++) {
		cout << nr_houses[i] << '\n';
	}

	return 0;
}