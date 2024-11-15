#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct VirusInfo
{
    int type;
    int x;
    int y;
    int time;

    VirusInfo(int type, int x, int y, int time) : type(type), x(x), y(y), time(time) {}

    bool operator<(const VirusInfo &virusInfo) const
    {
        return type < virusInfo.type;
    }
};

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int N, K;
int S, X, Y;
vector<vector<int>> grid;
vector<VirusInfo> virusInfos;

void Setup()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Input()
{
    cin >> N >> K;
    grid = vector<vector<int>>(N, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];

            if (grid[i][j] == 0)
                continue;

            virusInfos.push_back(VirusInfo(grid[i][j], i, j, 0));
        }
    }

    cin >> S >> X >> Y;
}

void Solve()
{
    sort(virusInfos.begin(), virusInfos.end(), less<VirusInfo>());

    queue<VirusInfo> virusQueue;
    for (const VirusInfo &virusInfo : virusInfos)
    {
        virusQueue.push(virusInfo);
    }

    while (!virusQueue.empty())
    {
        VirusInfo poppedVirusInfo = virusQueue.front();
        virusQueue.pop();

        if (poppedVirusInfo.x == X - 1 && poppedVirusInfo.y == Y - 1)
        {
            cout << grid[poppedVirusInfo.x][poppedVirusInfo.y] << "\n";
            return;
        }

        if (poppedVirusInfo.time == S)
        {
            cout << "0\n";
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = poppedVirusInfo.x + dx[i];
            int ny = poppedVirusInfo.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (grid[nx][ny] != 0)
                continue;

            grid[nx][ny] = poppedVirusInfo.type;
            virusQueue.push(VirusInfo(poppedVirusInfo.type, nx, ny, poppedVirusInfo.time + 1));
        }
    }

    cout << "0\n";
}

int main()
{
    Setup();
    Input();
    Solve();

    return 0;
}