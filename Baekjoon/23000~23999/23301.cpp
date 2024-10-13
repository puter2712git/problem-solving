#include <iostream>
#include <vector>

using namespace std;

int N, T;
vector<vector<int>> schedules;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> T;
    schedules = vector<vector<int>>(N, vector<int>(1001, 0));
    for (int i = 0; i < N; i++)
    {
        int K;
        cin >> K;
        for (int j = 0; j < K; j++)
        {
            int S, E;
            cin >> S >> E;
            for (int t = S; t < E; t++)
            {
                schedules[i][t] = 1;
            }
        }
    }

    int maxTime = 0;
    pair<int, int> maxTimeInterval = {0, 0};
    for (int i = 0; i < 1000 - T + 1; i++)
    {
        int currTime = 0;
        for (int j = i; j < i + T; j++)
        {
            for (const vector<int> &schedule : schedules)
            {
                if (schedule[j])
                {
                    currTime++;
                }
            }
        }

        if (currTime > maxTime)
        {
            maxTime = currTime;
            maxTimeInterval = {i, i + T};
        }
    }

    cout << maxTimeInterval.first << " " << maxTimeInterval.second << "\n";

    return 0;
}