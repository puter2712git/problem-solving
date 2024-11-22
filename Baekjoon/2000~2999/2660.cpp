#include <iostream>
#include <vector>

const int INF = 1'000'000;

int userCount;
std::vector<std::vector<int>> graph;
std::vector<std::vector<int>> dist;

void Setup()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

void Input()
{
    std::cin >> userCount;
    graph = std::vector<std::vector<int>>(userCount + 1, std::vector<int>(userCount + 1, 0));
    dist = std::vector<std::vector<int>>(userCount + 1, std::vector<int>(userCount + 1));

    int userA, userB;
    while (true)
    {
        std::cin >> userA >> userB;
        if (userA == -1 && userB == -1)
            break;

        graph[userA][userB] = 1;
        graph[userB][userA] = 1;
    }
}

void Solve()
{
    for (int i = 1; i <= userCount; i++)
    {
        for (int j = 1; j <= userCount; j++)
        {
            if (i == j)
            {
                dist[i][j] = 0;
            }
            else if (graph[i][j] != 0)
            {
                dist[i][j] = graph[i][j];
            }
            else
            {
                dist[i][j] = INF;
            }
        }
    }

    for (int k = 1; k <= userCount; k++)
    {
        for (int i = 1; i <= userCount; i++)
        {
            for (int j = 1; j <= userCount; j++)
            {
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int score = INF;
    int count = 0;
    std::vector<int> users;

    for (int i = 1; i <= userCount; i++)
    {
        int maxScore = 0;

        for (int j = 1; j <= userCount; j++)
        {
            if (maxScore < dist[i][j] && dist[i][j] != 0)
            {
                maxScore = dist[i][j];
            }
        }

        if (score > maxScore)
        {
            score = maxScore;
            count = 0;
            users.clear();
        }

        if (score == maxScore)
        {
            count++;
            users.push_back(i);
        }
    }

    std::cout << score << " " << count << "\n";
    for (int &user : users)
    {
        std::cout << user << " ";
    }
    std::cout << "\n";
}

int main()
{
    Setup();
    Input();
    Solve();

    return 0;
}