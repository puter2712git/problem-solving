#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> X;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    X = vector<int>(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> X[i];
    }

    sort(X.begin(), X.end());

    int x = X[1];
    int memberCount = 0;
    int teamCount = 0;
    for (int i = 1; i <= N; i++)
    {
        memberCount++;
        if (memberCount == x)
        {
            teamCount++;
            memberCount = 0;
            x = X[i + 1];
        }
    }
    if (memberCount != 0)
    {
        teamCount++;
    }

    cout << teamCount << "\n";

    return 0;
}