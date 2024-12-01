#include <iostream>
#include <queue>
#include <vector>

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int N, M;
std::vector<std::vector<int>> world;

int maxSafeAreaCount = 0;

void Setup()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

void Input()
{
    std::cin >> N >> M;
    world = std::vector<std::vector<int>>(N, std::vector<int>(M));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cin >> world[i][j];
        }
    }
}

int GetSafeArea()
{
    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<int>> tmpWorld(world);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (world[i][j] == 2)
            {
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        std::pair<int, int> poppedPosition = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = poppedPosition.first + dx[i];
            int ny = poppedPosition.second + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;

            if (tmpWorld[nx][ny] == 0)
            {
                tmpWorld[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (tmpWorld[i][j] == 0)
            {
                ret++;
            }
        }
    }

    return ret;
}

void BuildWall(int currWallCount = 0)
{
    if (currWallCount == 3)
    {
        maxSafeAreaCount = std::max<int>(maxSafeAreaCount, GetSafeArea());
        return;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (world[i][j] == 0)
            {
                world[i][j] = 1;
                BuildWall(currWallCount + 1);
                world[i][j] = 0;
            }
        }
    }
}

void Solve()
{
    BuildWall();
    std::cout << maxSafeAreaCount << "\n";
}

int main()
{
    Setup();
    Input();
    Solve();

    return 0;
}