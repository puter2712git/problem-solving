#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Edge
{
    int node;
    int weight;
};

int n;
vector<Edge> graph[10001];
bool visited[10001];

pair<int, int> FindFarthestVertexAndWeight(int startVertex)
{
    stack<pair<int, int>> stack;
    stack.push({ startVertex, 0 });

    int ret = 0;
    int maxWeight = 0;

    while (!stack.empty())
    {
        int currVertex = stack.top().first;
        int currWeight = stack.top().second;
        stack.pop();

        visited[currVertex] = true;

        for (Edge edge : graph[currVertex])
        {
            int nextVertex = edge.node;
            if (visited[nextVertex]) continue;

            int nextWeight = currWeight + edge.weight;

            if (nextWeight > maxWeight)
            {
                maxWeight = nextWeight;
                ret = nextVertex;
            }

            stack.push({ nextVertex, nextWeight });
        }
    }

    return { ret, maxWeight };
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back(Edge{ v, w });
        graph[v].push_back(Edge{ u, w });
    }

    for (int i = 1; i <= n; i++) visited[i] = false;
    int targetVertex = FindFarthestVertexAndWeight(1).first;
    
    for (int i = 1; i <= n; i++) visited[i] = false;
    int diameter = FindFarthestVertexAndWeight(targetVertex).second;

    cout << diameter << "\n";

    return 0;
}