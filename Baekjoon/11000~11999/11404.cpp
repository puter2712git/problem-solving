#include <iostream>
#include <vector>

using namespace std;

const int INF = (int)1e9;

int n;
int m;
vector<vector<int>> board;

void Setup()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Input()
{
    cin >> n;
    cin >> m;
    board = vector<vector<int>>(n + 1, vector<int>(n + 1, INF));

    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        board[a][b] = min(board[a][b], c);
    }
}

void Solve()
{
    for (int i = 1; i <= n; i++)
    {
        board[i][i] = 0;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                board[i][j] = min<int>(board[i][j], board[i][k] + board[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (board[i][j] == INF)
            {
                cout << "0 ";
            }
            else
            {
                cout << board[i][j] << " ";
            }
        }
        cout << "\n";
    }
}

int main()
{
    Setup();
    Input();
    Solve();

    return 0;
}