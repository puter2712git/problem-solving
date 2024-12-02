#include <iostream>
#include <vector>

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int R, C;
vector<vector<char>> board;
vector<vector<bool>> isVisited;
bool alphabets[26];

int maxCount;

void Setup()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Input()
{
    cin >> R >> C;
    board = vector<vector<char>>(R, vector<char>(C));
    isVisited = vector<vector<bool>>(R, vector<bool>(C, false));

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> board[i][j];
        }
    }
}

void Dfs(int x = 0, int y = 0, int count = 0)
{
    char alp = board[x][y];
    if (alphabets[alp - 'A'])
    {
        return;
    }

    maxCount = max<int>(maxCount, count + 1);

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= R || ny < 0 || ny >= C)
            continue;
        if (isVisited[nx][ny])
            continue;

        alphabets[alp - 'A'] = true;
        Dfs(nx, ny, count + 1);
        alphabets[alp - 'A'] = false;
    }
}

void Solve()
{
    isVisited[0][0] = true;
    Dfs();

    cout << maxCount << "\n";
}

int main()
{
    Setup();
    Input();
    Solve();

    return 0;
}