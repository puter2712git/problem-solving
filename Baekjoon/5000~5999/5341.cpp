#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int sum;

    while (true) {
        cin >> n;
        if (n == 0) break;

        sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i;
        }

        cout << sum << "\n";
    }

    return 0;
}