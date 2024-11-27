#include <iostream>

int N, K;

void Setup()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

void Input()
{
    std::cin >> N >> K;
}

bool IsAvailable(int n)
{
    int count = 0;

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            count++;
        }

        n /= 2;
    }

    return count <= K;
}

void Solve()
{
    int buyCount = 0;

    while (true)
    {
        if (IsAvailable(N + buyCount))
        {
            std::cout << buyCount << "\n";
            return;
        }

        buyCount++;
    }
}

int main()
{
    Setup();
    Input();
    Solve();

    return 0;
}