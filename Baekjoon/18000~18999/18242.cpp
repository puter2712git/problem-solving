#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<char>> rect;

pair<int, int> topLeft;
pair<int, int> bottomRight;

void SetTopLeft()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (rect[i][j] == '#')
            {
                topLeft = {i, j};
                return;
            }
        }
    }
}

void SetBottomRight()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (rect[N - i - 1][M - j - 1] == '#')
            {
                bottomRight = {N - i - 1, M - j - 1};
                return;
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
    rect = vector<vector<char>>(N, vector<char>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> rect[i][j];
        }
    }

    SetTopLeft();
    SetBottomRight();

    pair<int, int> mid = {(topLeft.first + bottomRight.first) / 2, (topLeft.second + bottomRight.second) / 2};

    if (rect[topLeft.first][mid.second] == '.')
    {
        cout << "UP\n";
    }
    else if (rect[mid.first][topLeft.second] == '.')
    {
        cout << "LEFT\n";
    }
    else if (rect[bottomRight.first][mid.second] == '.')
    {
        cout << "DOWN\n";
    }
    else if (rect[mid.first][bottomRight.second] == '.')
    {
        cout << "RIGHT\n";
    }

    return 0;
}