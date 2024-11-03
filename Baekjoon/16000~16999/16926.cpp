#include <deque>
#include <iostream>
#include <vector>

using namespace std;

const int dr[4] = {0, 1, 0, -1};
const int dc[4] = {1, 0, -1, 0};

int N, M, R;
vector<vector<int>> arr;

void Input()
{
    cin >> N >> M >> R;
    arr = vector<vector<int>>(N, vector<int>(M));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
}

void Solve()
{
    int loopCount = min(N, M) / 2;

    while (R--)
    {
        for (int i = 0; i < loopCount; i++)
        {
            int beginElement = arr[i][i];
            int r = i;
            int c = i;

            int j = 0;
            while (j < 4)
            {
                int nr = r + dr[j];
                int nc = c + dc[j];

                if (nr == i && nc == i)
                    break;

                if (i <= nr && nr < N - i && i <= nc && nc < M - i)
                {
                    arr[r][c] = arr[nr][nc];
                    r = nr;
                    c = nc;
                }
                else
                {
                    j++;
                }
            }

            arr[i + 1][i] = beginElement;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solve();

    return 0;
}