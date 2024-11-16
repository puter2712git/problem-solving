#include <iostream>
#include <vector>

int N, M;
std::vector<int> K;

void Setup()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

void Input()
{
    std::cin >> N >> M;
    K = std::vector<int>(M);

    for (int i = 0; i < M; i++)
    {
        std::cin >> K[i];
    }
}

void Solve()
{
    int result = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i % K[j] == 0)
            {
                result += i;
                break;
            }
        }
    }

    std::cout << result << "\n";
}

int main()
{
    Setup();
    Input();
    Solve();

    return 0;
}