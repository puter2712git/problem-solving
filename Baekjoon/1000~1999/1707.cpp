#include <iostream>
#include <vector>

using namespace std;

int K;
int V, E;

vector<vector<int>> adjList;

vector<int> flags;
bool isBipartite;

void Dfs(int startVertex, int flag)
{
    flags[startVertex] = flag;

    for (int v : adjList[startVertex])
    {
        if (flags[v] == flag)
        {
            isBipartite = false;
            return;
        }

        if (flags[v] == 0)
        {
            Dfs(v, -flag);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> K;

    while (K--)
    {
        cin >> V >> E;

        adjList = vector<vector<int>>(V + 1, vector<int>());
        flags = vector<int>(V + 1, 0);
        isBipartite = true;

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        for (int i = 1; i <= V; i++)
        {
            if (!isBipartite)
                break;

            if (flags[i] == 0)
            {
                Dfs(i, 1);
            }
        }

        if (isBipartite)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}