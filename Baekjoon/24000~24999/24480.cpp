#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, R;
vector<vector<int>> graph;
vector<bool> isVisited;
vector<int> visitOrders;
int order = 1;

void Dfs(int v)
{
	isVisited[v] = true;
	visitOrders[v] = order;
	order++;

	for (int vertex : graph[v]) {
		if (isVisited[vertex])
			continue;

		Dfs(vertex);
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
		sort(graph[i].begin(), graph[i].end(), greater<int>());
	}

	Dfs(R);

	for (int i = 1; i <= N; i++) {
		cout << visitOrders[i] << "\n";
	}

	return 0;
}