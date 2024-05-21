#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, K, X;
vector<vector<int>> graph;
vector<bool> visitFlags;
vector<int> minDistanceList;

void Bfs()
{
	queue<int> q;
	q.push(X);
	visitFlags[X] = true;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i < graph[curr].size(); i++) {
			if (visitFlags[graph[curr][i]])
				continue;

			q.push(graph[curr][i]);
			visitFlags[graph[curr][i]] = true;
			minDistanceList[graph[curr][i]] = minDistanceList[curr] + 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> K >> X;
	graph = vector<vector<int>>(N + 1);
	visitFlags = vector<bool>(N + 1, false);
	minDistanceList = vector<int>(N + 1, 0);

	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		graph[A].push_back(B);
	}

	Bfs();

	if (find(minDistanceList.begin(), minDistanceList.end(), K) != minDistanceList.end()) {
		for (int i = 1; i <= N; i++) {
			if (minDistanceList[i] == K) {
				cout << i << "\n";
			}
		}
	} else {
		cout << -1 << "\n";
	}

	return 0;
}