#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge
{
    int v0;
    int v1;
    int cost;

    bool operator<(const Edge &e) const
    {
        return cost < e.cost;
    }
};

int V, E;
vector<int> parent;
vector<Edge> edges;

int FindParent(int x)
{
    if (parent[x] != x)
    {
        parent[x] = FindParent(parent[x]);
    }
    return parent[x];
}

void UnionParent(int a, int b)
{
    a = FindParent(a);
    b = FindParent(b);

    if (a < b)
    {
        parent[b] = a;
    }
    else
    {
        parent[a] = b;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> V >> E;

    parent = vector<int>(V + 1);
    for (int i = 1; i <= V; i++)
        parent[i] = i;

    edges = vector<Edge>(E);
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].v0 >> edges[i].v1 >> edges[i].cost;
    }

    sort(edges.begin(), edges.end(), less<Edge>());

    long long totalCost = 0;

    for (Edge edge : edges)
    {
        if (FindParent(edge.v0) != FindParent(edge.v1))
        {
            UnionParent(edge.v0, edge.v1);
            totalCost += edge.cost;
        }
    }

    cout << totalCost << "\n";

    return 0;
}