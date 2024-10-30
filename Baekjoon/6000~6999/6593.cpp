#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct PositionInfo
{
    int l;
    int r;
    int c;
    int step;
};

const int dl[6] = {-1, 1, 0, 0, 0, 0};
const int dr[6] = {0, 0, -1, 1, 0, 0};
const int dc[6] = {0, 0, 0, 0, -1, 1};

int L, R, C;
vector<vector<vector<char>>> building;
vector<vector<vector<bool>>> isVisited;

void TryEscape(int startL, int startR, int startC)
{
    queue<PositionInfo> infos;
    infos.push({startL, startR, startC, 0});
    isVisited[startL][startR][startC] = true;

    while (!infos.empty())
    {
        PositionInfo poppedInfo = infos.front();
        infos.pop();

        for (int i = 0; i < 6; i++)
        {
            int l = poppedInfo.l + dl[i];
            int r = poppedInfo.r + dr[i];
            int c = poppedInfo.c + dc[i];

            if (l < 0 || l >= L || r < 0 || r >= R || c < 0 || c >= C)
                continue;
            if (building[l][r][c] == '#')
                continue;
            if (isVisited[l][r][c])
                continue;

            PositionInfo newInfo = {l, r, c, poppedInfo.step + 1};

            if (building[l][r][c] == 'E')
            {
                cout << "Escaped in " << newInfo.step << " minute(s).\n";
                return;
            }

            infos.push(newInfo);
            isVisited[l][r][c] = true;
        }
    }

    cout << "Trapped!\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int startL, startR, startC;

    while (true)
    {
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0)
            break;

        building = vector<vector<vector<char>>>(L, vector<vector<char>>(R, vector<char>(C)));
        isVisited = vector<vector<vector<bool>>>(L, vector<vector<bool>>(R, vector<bool>(C, false)));

        for (int l = 0; l < L; l++)
        {
            for (int r = 0; r < R; r++)
            {
                for (int c = 0; c < C; c++)
                {
                    cin >> building[l][r][c];

                    if (building[l][r][c] == 'S')
                    {
                        startL = l;
                        startR = r;
                        startC = c;
                    }
                }
            }
        }

        TryEscape(startL, startR, startC);
    }

    return 0;
}