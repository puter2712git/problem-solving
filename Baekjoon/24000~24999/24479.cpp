#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, R;
vector<vector<int>> graph;
vector<bool> visitFlags;
vector<int> visitOrders;
int order = 1;

void Dfs(int currVertex)
{
	visitFlags[currVertex] = true;
	visitOrders[currVertex] = order++;

	for (int i = 0; i < graph[currVertex].size(); i++) {
		if (visitFlags[graph[currVertex][i]])
			continue;

		Dfs(graph[currVertex][i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> R;
	graph = vector<vector<int>>(N + 1, vector<int>());
	visitFlags = vector<bool>(N + 1, false);
	visitOrders = vector<int>(N + 1, 0);

	for (int i = 0; i < M; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end(), less<int>());
	}

	Dfs(R);

	for (int i = 1; i <= N; i++) {
		cout << visitOrders[i] << "\n";
	}

	return 0;
}