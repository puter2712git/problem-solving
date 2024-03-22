#include <iostream>

using namespace std;

int GetGCD(int a, int b)
{
    if (a % b == 0) {
        return b;
    } else {
        return GetGCD(b, a % b);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int numerator, denominator;
    char tmp;
    cin >> numerator >> tmp >> denominator;

    int gcd = GetGCD(numerator, denominator);

    cout << numerator / gcd << ":" << denominator / gcd << "\n";

    return 0;
}