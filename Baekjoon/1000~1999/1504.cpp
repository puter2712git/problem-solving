#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 800'000 * 2 + 1'001;

struct Edge
{
    int vertex;
    int weight;

    bool operator>(const Edge &e) const
    {
        return weight > e.weight;
    }
};

int N, E;
vector<vector<Edge>> adj;

int v1, v2;

vector<int> dists;

int Dijkstra(int startVertex, int endVertex)
{
    dists = vector<int>(N + 1, INF);
    vector<bool> isVisited(N + 1, false);

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    pq.push(Edge{startVertex, 0});
    dists[startVertex] = 0;

    while (!pq.empty())
    {
        Edge curr = pq.top();
        pq.pop();

        if (isVisited[curr.vertex])
            continue;

        isVisited[curr.vertex] = true;

        for (int i = 0; i < (int)adj[curr.vertex].size(); i++)
        {
            Edge next = adj[curr.vertex][i];

            if (dists[next.vertex] > dists[curr.vertex] + next.weight)
            {
                dists[next.vertex] = dists[curr.vertex] + next.weight;
                pq.push(Edge{next.vertex, dists[next.vertex]});
            }
        }
    }

    return dists[endVertex];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> E;

    adj = vector<vector<Edge>>(N + 1, vector<Edge>());

    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back(Edge{b, c});
        adj[b].push_back(Edge{a, c});
    }

    cin >> v1 >> v2;

    dists = vector<int>(N + 1, 0);

    int ans0 = 0;
    ans0 += Dijkstra(1, v1);
    ans0 += Dijkstra(v1, v2);
    ans0 += Dijkstra(v2, N);

    int ans1 = 0;
    ans1 += Dijkstra(1, v2);
    ans1 += Dijkstra(v2, v1);
    ans1 += Dijkstra(v1, N);

    int ans = ans0 >= INF && ans1 >= INF ? -1 : min<int>(ans0, ans1);
    cout << ans << "\n";

    return 0;
}