#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<vector<int>> S(20, vector<int>(20));

vector<bool> is_visited(20, false);
int min_diff = INT32_MAX;

int get_diff()
{
	int start = 0, link = 0;
	vector<int> start_team;
	vector<int> link_team;

	for (int i = 0; i < N; i++) {
		if (is_visited[i]) {
			start_team.push_back(i);
		} else {
			link_team.push_back(i);
		}
	}

	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N / 2; j++) {
			start += S[start_team[i]][start_team[j]];
			link += S[link_team[i]][link_team[j]];
		}
	}

	return abs(start - link);
}

void find_min_diff(int depth = 1, int last_index = 1)
{
	if (depth == N / 2) {
		min_diff = min(min_diff, get_diff());
		return;
	}

	for (int i = last_index; i < N; i++) {
		if (is_visited[i]) continue;

		is_visited[i] = true;
		find_min_diff(depth + 1, i + 1);
		is_visited[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> S[i][j];
		}
	}

	is_visited[0] = true;
	find_min_diff();
	cout << min_diff << "\n";

	return 0;
}