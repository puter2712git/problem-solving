#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int city[301][301];
bool visited[301][301];

void bfs(int startX, int startY)
{
    queue<pair<int, int>> q;
    visited[startX][startY] = true;
    q.push({startX, startY});

    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();

        if (curr.first + 1 < M)
        {
            if (city[curr.first + 1][curr.second] == 1 && !visited[curr.first + 1][curr.second])
            {
                q.push({curr.first + 1, curr.second});
                visited[curr.first + 1][curr.second] = true;
            }
        }

        if (curr.second + 1 < N)
        {
            if (city[curr.first][curr.second + 1] == 1 && !visited[curr.first][curr.second + 1])
            {
                q.push({curr.first, curr.second + 1});
                visited[curr.first][curr.second + 1] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> city[i][j];
            visited[i][j] = false;
        }
    }

    bfs(0, 0);

    if (visited[M - 1][N - 1])
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}