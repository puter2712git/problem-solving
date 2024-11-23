#include <iostream>

const int INF = 51;

int N;
int dice[6];
int maxDie = 0;
int minDice[3] = {51, 101, 151};

void Setup()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

void Input()
{
    std::cin >> N;
    for (int i = 0; i < 6; i++)
    {
        std::cin >> dice[i];
    }
}

void Solve()
{
    for (int i = 0; i < 6; i++)
    {
        maxDie = std::max(maxDie, dice[i]);
    }

    long long answer = 0;

    if (N == 1)
    {
        for (int i = 0; i < 6; i++)
        {
            answer += dice[i];
        }
        std::cout << answer - maxDie << "\n";
        return;
    }

    for (int i = 0; i < 6; i++)
    {
        minDice[0] = std::min(minDice[0], dice[i]);
        for (int j = i + 1; j < 6; j++)
        {
            if (i + j == 5)
                continue;

            minDice[1] = std::min(minDice[1], dice[i] + dice[j]);
            for (int k = j + 1; k < 6; k++)
            {
                if (j + k == 5 || i + k == 5)
                    continue;

                minDice[2] = std::min(minDice[2], dice[i] + dice[j] + dice[k]);
            }
        }
    }

    answer += (5 * (long long)N * N - 16 * N + 12) * minDice[0];
    answer += 4 * minDice[2];
    answer += (8 * N - 12) * minDice[1];

    std::cout << answer << "\n";
}

int main()
{
    Setup();
    Input();
    Solve();

    return 0;
}