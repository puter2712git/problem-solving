#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};

int N, M;
vector<vector<int>> table;
vector<vector<int>> ctable;
vector<vector<bool>> visited;

void Bfs(int row, int col)
{
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = true;

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                continue;
            if (visited[nr][nc] || table[nr][nc] == 0)
                continue;

            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }
}

int Pass()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = false;
        }
    }

    int traverseCnt = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (table[i][j] == 0 || visited[i][j])
                continue;

            traverseCnt++;
            Bfs(i, j);
        }
    }

    return traverseCnt;
}

int Melt(int row, int col)
{
    int meltCnt = 0;

    for (int i = 0; i < 4; i++)
    {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (table[nr][nc] == 0)
        {
            meltCnt++;
        }
    }

    return meltCnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    table = vector<vector<int>>(N, vector<int>(M, 0));
    ctable = vector<vector<int>>(N, vector<int>(M, 0));
    visited = vector<vector<bool>>(N, vector<bool>(M, false));

    for (vector<int> &t : table)
    {
        for (int &n : t)
        {
            cin >> n;
        }
    }

    int passedYear = 0;

    while (true)
    {
        int traverseCnt = Pass();
        if (traverseCnt >= 2)
        {
            cout << passedYear << "\n";
            return 0;
        }
        if (traverseCnt == 0)
        {
            cout << "0\n";
            return 0;
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (table[i][j] == 0)
                    continue;

                ctable[i][j] = table[i][j] - Melt(i, j);
                if (ctable[i][j] < 0)
                {
                    ctable[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                table[i][j] = ctable[i][j];
            }
        }

        passedYear++;
    }

    return 0;
}