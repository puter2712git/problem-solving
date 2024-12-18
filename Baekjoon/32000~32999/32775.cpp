#include <iostream>

using namespace std;

int sab, fab;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> sab;
    cin >> fab;

    if (sab <= fab)
    {
        cout << "high speed rail\n";
    }
    else
    {
        cout << "flight\n";
    }

    return 0;
}