#include <iostream>
#include <regex>

int T;

void Setup()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

void Input()
{
    std::cin >> T;
}

void Solve()
{
    std::string signal;
    std::regex pattern("(100+1+|01)+");

    while (T--)
    {
        std::cin >> signal;

        if (std::regex_match(signal, pattern))
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
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