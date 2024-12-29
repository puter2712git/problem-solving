#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int M;
int parents[201];

int FindParent(int v)
{
    if (parents[v] == v) return v;
    return parents[v] = FindParent(parents[v]);
}

void Union(int v0, int v1)
{
    v0 = FindParent(v0);
    v1 = FindParent(v1);
    if (v0 < v1) parents[v1] = v0;
    else parents[v0] = v1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    cin >> M;

    for (int i = 1; i <= N; i++)
    {
        parents[i] = i;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int v;
            cin >> v;
            if (v == 1)
            {
                Union(i, j);
            }
        }
    }

    int root;
    for (int i = 0; i < M; i++)
    {
        int v;
        cin >> v;
        if (i == 0)
        {
            root = FindParent(v);
        }
        else
        {
            if (FindParent(root) != FindParent(v))
            {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
    return 0;
}