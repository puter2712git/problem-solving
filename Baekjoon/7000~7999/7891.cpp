#include <iostream>

using namespace std;

int t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;

    int x, y;
    while (t--)
    {
        cin >> x >> y;
        cout << x + y << "\n";
    }

    return 0;
}