#include <iostream>

using namespace std;

long long GetGCD(long long a, long long b)
{
    if (a % b == 0) {
        return b;
    } else {
        return GetGCD(b, a % b);
    }
}

long long GetLCM(long long a, long long b)
{
    return (a * b) / GetGCD(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testcase;
    cin >> testcase;

    for (int i = 0; i < testcase; i++) {
        long long a, b;

        cin >> a >> b;
        cout << GetLCM(a, b) << "\n";
    }

    return 0;
}