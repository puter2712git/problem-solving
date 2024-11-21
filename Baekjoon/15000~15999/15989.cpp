#include <iostream>
#include <vector>

int T;
int n;
std::vector<std::vector<int>> dp;

void Setup()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    dp = std::vector<std::vector<int>>(10'001, std::vector<int>(4));
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    for (int i = 4; i <= 10'000; i++)
    {
        dp[i][1] = dp[i - 1][1];
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
        dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
    }
}

void Input()
{
    std::cin >> T;
}

void Solve()
{
    while (T--)
    {
        std::cin >> n;
        std::cout << dp[n][1] + dp[n][2] + dp[n][3] << "\n";
    }
}

int main()
{
    Setup();
    Input();
    Solve();

    return 0;
}