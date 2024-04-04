#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int participantLength;
    int num1;
    int num2;

    cin >> participantLength >> num1 >> num2;

    int count = 0;

    while (num1 != num2) {
        num1 -= num1 / 2;
        num2 -= num2 / 2;
        count++;
    }

    cout << count << "\n";

    return 0;
}