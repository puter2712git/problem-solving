#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int numerator, denominator;
    int index;

    int result;

    cin >> numerator >> denominator >> index;

    for (int i = 0; i < index; i++) {
        numerator %= denominator;
        numerator *= 10;
        result = numerator / denominator;
    }

    cout << result << "\n";

    return 0;
}