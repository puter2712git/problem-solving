#include <iostream>

using namespace std;

bool is_bigO_satisfied(int a1, int a0, int c, int n0)
{
    int f = a1 * n0 + a0;
    int g = c * n0;

    return f <= g && a1 <= c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a1, a0;
    int c;
    int n0;

    cin >> a1 >> a0;
    cin >> c;
    cin >> n0;

    cout << is_bigO_satisfied(a1, a0, c, n0) << "\n";

    return 0;
}