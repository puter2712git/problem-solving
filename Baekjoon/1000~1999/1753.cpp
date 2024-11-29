#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

const int INF = 1e9;

int V, E;
int startVertex;
std::vector<std::vector<std::pair<int, int>>> graph;

void Setup()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

void Input()
{
    std::cin >> V >> E;
    std::cin >> startVertex;

    graph = std::vector<std::vector<std::pair<int, int>>>(V + 1);

    int u, v, w;
    for (int i = 0; i < E; i++)
    {
        std::cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
}

void Solve()
{
    std::priority_queue<std::pair<int, int>> pq;
    pq.push({0, startVertex});

    std::vector<int> dists(V + 1, INF);
    dists[startVertex] = 0;

    while (!pq.empty())
    {
        int weight = -pq.top().first;
        int currVertex = pq.top().second;
        pq.pop();

        for (int i = 0; i < (int)graph[currVertex].size(); i++)
        {
            int nextVertex = graph[currVertex][i].first;
            int nextWeight = graph[currVertex][i].second;

            if (dists[nextVertex] > weight + nextWeight)
            {
                dists[nextVertex] = weight + nextWeight;
                pq.push({-dists[nextVertex], nextVertex});
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (dists[i] == INF)
        {
            std::cout << "INF" << "\n";
        }
        else
        {
            std::cout << dists[i] << "\n";
        }
    }
}

int main()
{
    Setup();
    Input();
    Solve();

    return 0;
}