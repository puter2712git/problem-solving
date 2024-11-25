#include <algorithm>
#include <iostream>
#include <memory.h>
#include <vector>

int T, W;
std::vector<int> plumPositions;

int dp[1001][31];

void Setup()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    memset(dp, 0, sizeof(dp));
}

void Input()
{
    std::cin >> T >> W;

    plumPositions = std::vector<int>(T + 1);
    for (int i = 1; i <= T; i++)
    {
        std::cin >> plumPositions[i];
    }
}

void FillDP()
{
    dp[1][0] = plumPositions[1] % 2;
    dp[1][1] = plumPositions[1] / 2;
    for (int i = 2; i <= T; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            int plum;
            if (j % 2 == 0)
            {
                plum = plumPositions[i] % 2;
            }
            else
            {
                plum = plumPositions[i] / 2;
            }

            dp[i][j] = *std::max_element(dp[i - 1], dp[i - 1] + j + 1) + plum;
        }
    }
}

void Solve()
{
    FillDP();
    std::cout << *std::max_element(dp[T], dp[T] + W + 1) << "\n";
}

int main()
{
    Setup();
    Input();
    Solve();

    return 0;
}