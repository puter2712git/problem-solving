#include <iostream>

int N;

void Setup()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

void Input()
{
    std::cin >> N;
}

void Solve()
{
    long long S;

    for (int i = 0; i < N; i++)
    {
        std::cin >> S;
        bool isPassKey = true;

        for (int j = 2; j <= 1'000'000; j++)
        {
            if (S % j == 0)
            {
                std::cout << "NO\n";
                isPassKey = false;
                break;
            }
        }

        if (isPassKey)
        {
            std::cout << "YES\n";
        }
    }
}

int main()
{
    Setup();
    Input();
    Solve();

    return 0;
}