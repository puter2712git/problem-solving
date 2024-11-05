#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int N, H;
vector<int> bottomUps, topDowns;

void Setup()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Input()
{
    cin >> N >> H;
    bottomUps = vector<int>(H + 1, 0);
    topDowns = vector<int>(H + 1, 0);

    int height;
    for (int i = 0; i < N; i++)
    {
        cin >> height;

        if (i % 2 == 0)
        {
            bottomUps[height]++;
        }
        else
        {
            topDowns[H - height + 1]++;
        }
    }
}

void Solve()
{
    for (int i = 1; i <= H; i++)
    {
        bottomUps[H - i] += bottomUps[H - i + 1];
        topDowns[i] += topDowns[i - 1];
    }

    int answer = INT_MAX;
    int count = 0;

    for (int i = 1; i <= H; i++)
    {
        int obstacleCount = topDowns[i] + bottomUps[i];

        if (obstacleCount < answer)
        {
            count = 1;
            answer = obstacleCount;
        }
        else if (obstacleCount == answer)
        {
            count++;
        }
    }

    cout << answer << " " << count << "\n";
}

int main()
{
    Setup();
    Input();
    Solve();

    return 0;
}