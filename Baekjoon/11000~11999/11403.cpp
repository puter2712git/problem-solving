#include <iostream>

using namespace std;

void set_graph(int graph[][100], int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				if (graph[j][i] && graph[i][k]) {
					graph[j][k] = 1;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int v_count;
	int graph[100][100];

	cin >> v_count;
	for (int i = 0; i < v_count; i++) {
		for (int j = 0; j < v_count; j++) {
			cin >> graph[i][j];
		}
	}

	set_graph(graph, v_count);

	for (int i = 0; i < v_count; i++) {
		for (int j = 0; j < v_count; j++) {
			cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}