#include <iostream>
#include <cmath>

using namespace std;

int T;
int x;

long long GetTime(int target)
{
    long long exp = 0;

    while (pow(2, exp) < abs(target))
    {
        exp++;
    }

    if (target == 0)
    {
        return 0;
    }
    else if (target > 0)
    {
        return 5 * pow(2, exp) - 4 - (pow(2, exp) - x);
    }
    else
    {
        return (5 * pow(2, exp) - 4 + pow(2, (exp + 1))) - (pow(2, exp) - abs(target));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    while (T--)
    {
        cin >> x;

        cout << GetTime(x) << "\n";
    }

    return 0;
}