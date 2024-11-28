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
    if (N <= 2)
    {
        N = 4;
    }

    if (N % 2 == 0)
    {
        std::cout << N << "\n";
    }
    else
    {
        std::cout << N + 1 << "\n";
    }
}

int main()
{
    Setup();
    Input();
    Solve();

    return 0;
}