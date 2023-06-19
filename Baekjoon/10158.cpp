#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int w, h;
    int p, q;
    int t;

    cin >> w >> h;
    cin >> p >> q;
    cin >> t;

    p += t;
    q += t;

    p %= 2 * w;
    q %= 2 * h;

    if (p > w) {
        p = 2 * w - p;
    }
    if (q > h) {
        q = 2 * h - q;
    }

    cout << p << " " << q << "\n";

    return 0;
}