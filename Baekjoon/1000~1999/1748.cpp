#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int num;
    cin >> num;

    int digitCount = 0;

    if (num < 10) {
        cout << num << "\n";
        return 0;
    }

    for (int i = 1; i <= num; i *= 10) {
        digitCount += num - i + 1;
    }

    cout << digitCount << "\n";

    return 0;
}