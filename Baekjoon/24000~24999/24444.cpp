#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, R;
vector<vector<int>> graph;
vector<bool> isVisited;
vector<int> visitOrders;

int order = 1;

void Bfs(int index)
{
	queue<int> q;
	q.push(index);
	isVisited[index] = true;
	visitOrders[index] = order;
	order++;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int next : graph[curr]) {
			if (isVisited[next])
				continue;

			isVisited[next] = true;
			visitOrders[next] = order;
			order++;

			q.push(next);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> R;
	graph = vector<vector<int>>(N + 1, vector<int>());
	isVisited = vector<bool>(N + 1, false);
	visitOrders = vector<int>(N + 1, 0);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end(), less<int>());
	}

	Bfs(R);

	for (int i = 1; i <= N; i++) {
		cout << visitOrders[i] << "\n";
	}

	return 0;
}