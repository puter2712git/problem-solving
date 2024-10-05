#include <iostream>
#include <vector>

using namespace std;

int N;
vector<long long> A;
vector<long long> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    A = vector<long long>(N + 1);
    dp = vector<long long>(N + 1, 0);
    long long minValue = 1'000'000'001;

    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        minValue = min(minValue, A[i]);

        if (i == 1)
        {
            dp[i] = 0;
        }
        else
        {
            dp[i] = max(dp[i - 1], A[i] - minValue);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << dp[i] << " ";
    }
    cout << "\n";

    return 0;
}