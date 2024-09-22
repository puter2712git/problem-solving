#include <iostream>

using namespace std;

int N;
int tiles[501][501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    int x1, y1, x2, y2;
    for (int i = 0; i < N; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x = x1; x < x2; x++)
        {
            for (int y = y1; y < y2; y++)
            {
                tiles[x][y] = 1;
            }
        }
    }

    int area = 0;
    for (int i = 0; i < 501; i++)
    {
        for (int j = 0; j < 501; j++)
        {
            if (tiles[i][j] == 1)
            {
                area++;
            }
        }
    }

    cout << area << "\n";

    return 0;
}