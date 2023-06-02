#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, b, c, d, e, f;
    int x, y;

    cin >> a >> b >> c >> d >> e >> f;

    x = (c * e - b * f) / (a * e - b * d);
    y = (c * d - a * f) / (b * d - a * e);

    cout << x << " " << y << "\n";

    return 0;
}