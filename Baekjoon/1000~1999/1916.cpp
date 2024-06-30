#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int s, e;
vector<vector<pair<int, int>>> cities;

vector<int> minDists;

void SetMinDists()
{
	minDists[s] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push({ minDists[s], s });

	while (!pq.empty()) {
		int currCity = pq.top().second;
		int currDist = -pq.top().first;
		pq.pop();

		if (minDists[currCity] < currDist)
			continue;

		for (int i = 0; i < cities[currCity].size(); i++) {
			int nextCity = cities[currCity][i].first;
			int nextDist = currDist + cities[currCity][i].second;

			if (nextDist < minDists[nextCity]) {
				minDists[nextCity] = nextDist;
				pq.push({ -nextDist, nextCity });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	cin >> M;
	minDists = vector<int>(N + 1, numeric_limits<int>::max());
	cities = vector<vector<pair<int, int>>>(N + 1, vector<pair<int, int>>());

	for (int i = 0; i < M; i++) {
		int startCity, endCity, dist;
		cin >> startCity >> endCity >> dist;
		cities[startCity].push_back({ endCity, dist });
	}

	cin >> s >> e;

	SetMinDists();
	cout << minDists[e] << "\n";

	return 0;
}