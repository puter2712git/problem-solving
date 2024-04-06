#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testcase;
    cin >> testcase;

    for (int i = 0; i < testcase; i++) {
        int nationLength;
        int planeLength;
        cin >> nationLength >> planeLength;

        for (int j = 0; j < planeLength; j++) {
            int a, b;
            cin >> a >> b;
        }

        cout << nationLength - 1 << "\n";
    }

    return 0;
}