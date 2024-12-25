#include <iostream>

using namespace std;

// RIGHT UP LEFT DOWN
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int R, C, T;
int A[50][50];
int ATmp[50][50];

int upside = -1;
int downside = -1;

void Spread(int row, int col)
{
    int spreadAmount = A[row][col] / 5;
    int spreadCount = 0;

    for (int i = 0; i < 4; i++)
    {
        int nx = col + dx[i];
        int ny = row + dy[i];

        if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
        if (A[ny][nx] < 0) continue;

        ATmp[ny][nx] += spreadAmount;
        spreadCount += 1;
    }

    ATmp[row][col] -= spreadAmount * spreadCount;
}

void SpreadAll()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (A[i][j] == -1) continue;

            ATmp[i][j] = A[i][j];
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (A[i][j] <= 0) continue;

            Spread(i, j);
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (A[i][j] == -1) continue;

            A[i][j] = ATmp[i][j];
        }
    }
}

void Purify()
{
    int x, y;
    int index;
    int tmp;

    // Upside
    x = 0;
    y = upside;
    index = 0;
    tmp = 0;

    while (true)
    {
        int nx = x + dx[index];
        int ny = y + dy[index];

        if (nx < 0 || nx >= C || ny < 0 || ny >= R)
        {
            index = (index + 1) % 4;
            continue;
        }
        if (A[ny][nx] == -1) break;

        swap(tmp, A[ny][nx]);
        x = nx;
        y = ny;
    }

    // Downside
    x = 0;
    y = downside;
    index = 0;
    tmp = 0;

    while (true)
    {
        int nx = x + dx[index];
        int ny = y + dy[index];

        if (nx < 0 || nx >= C || ny < 0 || ny >= R)
        {
            index -= 1;
            if (index < 0) index += 4;
            continue;
        }
        if (A[ny][nx] == -1) break;

        swap(tmp, A[ny][nx]);
        x = nx;
        y = ny;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> C >> T;
    
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> A[i][j];

            if (A[i][j] == -1)
            {
                if (upside == -1) upside = i;
                else downside = i;
            }
        }
    }

    while (T--)
    {
        SpreadAll();
        Purify();
    }

    int dust = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (A[i][j] == -1) continue;

            dust += A[i][j];
        }
    }

    cout << dust << "\n";

    return 0;
}