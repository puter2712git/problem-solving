#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge
{
    int v0;
    int v1;
    int weight;

    bool operator<(const Edge& e);
};

bool Edge::operator<(const Edge& e)
{
    return weight < e.weight;
}

int N;
int M;
int parents[1001];
Edge edges[100001];

int FindParent(int v)
{
    if (parents[v] == v) return v;
    return parents[v] = FindParent(parents[v]);
}

void UnionParent(int v0, int v1)
{
    v0 = FindParent(v0);
    v1 = FindParent(v1);

    if (v0 != v1)
    {
        parents[v1] = v0;
    }
}

vector<Edge> GetMST()
{
    vector<Edge> mst;

    for (Edge edge : edges)
    {
        int v0 = edge.v0;
        int v1 = edge.v1;

        if (FindParent(v0) == FindParent(v1)) continue;

        mst.push_back(edge);
        UnionParent(v0, v1);

        if ((int)mst.size() == N - 1) break;
    }

    return mst;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> edges[i].v0 >> edges[i].v1 >> edges[i].weight;
    }

    sort(edges, edges + M);
    for (int i = 1; i <= N; i++)
    {
        parents[i] = i;
    }

    vector<Edge> mst = GetMST();
    int totalWeight = 0;

    for (Edge edge : mst)
    {
        totalWeight += edge.weight;
    }

    cout << totalWeight << "\n";

    return 0;
}