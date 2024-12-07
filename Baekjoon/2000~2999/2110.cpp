#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, C;
vector<int> locations;

int GetInstallCount(int dist)
{
    int count = 1;
    int currLoc = locations[0];

    for (int i = 1; i < N; i++)
    {
        int loc = locations[i];

        if (loc - currLoc >= dist)
        {
            count++;
            currLoc = loc;
        }
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> C;

    locations = vector<int>(N);
    for (int i = 0; i < N; i++)
    {
        cin >> locations[i];
    }

    sort(locations.begin(), locations.end(), less<int>());

    int low = 1;
    int high = locations[N - 1] - locations[0] + 1;

    while (low < high)
    {
        int mid = (low + high) / 2;

        if (GetInstallCount(mid) < C)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << low - 1 << "\n";

    return 0;
}