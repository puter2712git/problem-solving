#include <iostream>
#include <vector>

int N, M;
std::vector<std::string> oxs;

void Setup()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

void Input()
{
    std::cin >> N >> M;

    oxs = std::vector<std::string>(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> oxs[i];
    }
}

bool IsApproved(const std::string &ox)
{
    int oCount = 0;

    for (int i = 0; i < M; i++)
    {
        if (ox[i] == 'O')
        {
            oCount++;
        }
    }

    return oCount > M / 2;
}

void Solve()
{
    int approveCount = 0;

    for (int i = 0; i < N; i++)
    {
        if (IsApproved(oxs[i]))
        {
            approveCount++;
        }
    }

    std::cout << approveCount << "\n";
}

int main()
{
    Setup();
    Input();
    Solve();

    return 0;
}