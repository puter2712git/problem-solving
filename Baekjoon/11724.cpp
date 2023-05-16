#include <iostream>
#include <vector>

using namespace std;

void get_connected_component(vector<int> g[], int curr_vertex, bool visited[])
{
	visited[curr_vertex] = true;

	for (int i = 0; i < g[curr_vertex].size(); i++) {
		if (!visited[g[curr_vertex][i]]) {
			get_connected_component(g, g[curr_vertex][i], visited);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> graph[1001];
	bool visited[1001] = { false, };

	int vertex_count;
	int edge_count;

	int answer = 0;

	cin >> vertex_count >> edge_count;
	
	while (edge_count--) {
		int begin, end;
		cin >> begin >> end;

		graph[begin].push_back(end);
		graph[end].push_back(begin);
	}

	for (int i = 1; i <= vertex_count; i++) {
		if (!visited[i]) {
			answer++;
			get_connected_component(graph, i, visited);
		}
	}

	cout << answer << '\n';

	return 0;
}