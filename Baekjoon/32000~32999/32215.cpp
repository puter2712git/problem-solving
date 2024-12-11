#include <iostream>

using namespace std;

int n, m, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;

    cout << m * k + m << "\n";

    return 0;
}