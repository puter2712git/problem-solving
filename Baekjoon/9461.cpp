#include <iostream>

using namespace std;

unsigned long long dp[101] = { 0, 1, 1, 1, };

int test_count;
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> test_count;

    while (test_count--) {
        cin >> n;

        for (int i = 4; i <= n; i++) {
            dp[i] = dp[i - 2] + dp[i - 3];
        }

        cout << dp[n] << '\n';
    }


    return 0;
}