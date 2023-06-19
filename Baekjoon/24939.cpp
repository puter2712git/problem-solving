#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    int Q;
    long long x, y, d;

    long long x1, x2, y1, y2;

    cin >> N >> M;
    cin >> Q;

    x1 = 1, y1 = 1;
    x2 = N, y2 = M;

    for (int i = 0; i < Q; i++) {
        cin >> x >> y >> d;

        switch (d) {
        // 1: 동쪽
        case 1:
            if (x1 < x + 1) x1 = x + 1;
            y1 = y;
            y2 = y;
            break;

        // 2: 서쪽
        case 2:
            if (x2 > x - 1) x2 = x - 1;
            y1 = y;
            y2 = y;
            break;

        // 3: 남쪽
        case 3:
            x1 = x;
            x2 = x;
            if (y2 > y - 1) y2 = y - 1;
            break;

        // 4: 북쪽
        case 4:
            x1 = x;
            x2 = x;
            if (y1 < y + 1) y1 = y + 1;
            break;

        // 5: 북동쪽
        case 5:
            if (x1 < x + 1) x1 = x + 1;
            if (y1 < y + 1) y1 = y + 1;
            break;

        // 6: 북서쪽
        case 6:
            if (x2 > x - 1) x2 = x - 1;
            if (y1 < y + 1) y1 = y + 1;
            break;

        // 7: 남동쪽
        case 7:
            if (x1 < x + 1) x1 = x + 1;
            if (y2 > y - 1) y2 = y - 1;
            break;

        // 8: 남서쪽
        case 8:
            if (x2 > x - 1) x2 = x - 1;
            if (y2 > y - 1) y2 = y - 1;
            break;

        case 9:
            x1 = x;
            x2 = x;
            y1 = y;
            y2 = y;
            break;
        }
    }

    long long area = (x2 - x1 + 1) * (y2 - y1 + 1);

    cout << area << "\n";

    return 0;
}