#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> T;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    T = vector<int>(n + 1, 0);
    vector<long long> sums(n + 1, 0);
    long long tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> T[i];
        tmp += T[i];
        sums[i] = tmp;
    }

    long long maxSum = 0;
    for (int i = 0; i <= n - m; i++)
    {
        maxSum = max<long long>(maxSum, sums[i + m] - sums[i]);
    }

    cout << maxSum << "\n";

    return 0;
}