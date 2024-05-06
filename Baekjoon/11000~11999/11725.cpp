#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
vector<vector<int>> tree;
vector<bool> isVisited;
vector<int> parents;

void bfs()
{
	queue<int> q;
	q.push(1);
	isVisited[1] = true;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i < tree[curr].size(); ++i) {
			int child = tree[curr][i];
			if (isVisited[child])
				continue;

			parents[child] = curr;
			isVisited[child] = true;
			q.push(child);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	tree = vector<vector<int>>(N + 1, vector<int>());
	isVisited = vector<bool>(N + 1, false);
	parents = vector<int>(N + 1, 0);

	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	bfs();

	for (int i = 2; i <= N; ++i) {
		cout << parents[i] << "\n";
	}

	return 0;
}