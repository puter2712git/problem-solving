#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int stickCount = 0;
    int targetLen;
    cin >> targetLen;

    while (targetLen > 0) {
        if (targetLen % 2 == 1) {
            stickCount++;
        }
        targetLen /= 2;
    }

    cout << stickCount << "\n";

    return 0;
}