#include <iostream>
#include <cmath>

using namespace std;

int GetPosCount(int x1, int y1, int r1, int x2, int y2, int r2)
{
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    // 두 원이 일치
    if (distance == 0 && r1 == r2)
    {
        return -1;
    }

    // 두 점에서 만나는 경우
    else if (distance > abs(r1 - r2) && distance < r1 + r2)
    {
        return 2;
    }

    // 접하는 경우
    if ((distance == r1 + r2) || (distance == abs(r1 - r2)))
    {
        return 1;
    }

    // 그 외 만나지 않는 경우
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testcaseLength;
    cin >> testcaseLength;

    for (int i = 0; i < testcaseLength; i++)
    {
        int x1, y1, r1;
        int x2, y2, r2;

        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        cout << GetPosCount(x1, y1, r1, x2, y2, r2) << "\n";
    }

    return 0;
}