#include <iostream>
#include <vector>

using namespace std;

int GetGCD(int a, int b)
{
    if (b == 0) {
        return a;
    } else {
        return GetGCD(b, a % b);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ringLength;
    int firstRing;

    cin >> ringLength;
    for (int i = 0; i < ringLength; i++) {
        int tmp;
        cin >> tmp;

        if (i == 0) {
            firstRing = tmp;
        } else {
            int gcd = firstRing > tmp ? GetGCD(firstRing, tmp) : GetGCD(tmp, firstRing);
            cout << firstRing / gcd << "/" << tmp / gcd << "\n";
        }
    }

    return 0;
}