#include <iostream>

using namespace std;

int T;
int A, B, X;

int GetGCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return GetGCD(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    while (T--)
    {
        cin >> A >> B >> X;
        int gcd = GetGCD(A, B);
        cout << X / gcd << "\n";
    }

    return 0;
}