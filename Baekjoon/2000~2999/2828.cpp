#include <cmath>
#include <iostream>
#include <utility>

using namespace std;

bool IsInRange(pair<int, int>& bucketPos, int applePos)
{
    int start = bucketPos.first;
    int end = bucketPos.second;

    bool ret = start <= applePos && end >= applePos;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int screenWidth;
    int bucketWidth;
    int appleCount;

    int movedSum = 0;

    cin >> screenWidth >> bucketWidth;
    cin >> appleCount;

    pair<int, int> pos = make_pair(1, bucketWidth);

    for (int i = 0; i < appleCount; i++) {
        int tmp;
        cin >> tmp;

        if (IsInRange(pos, tmp))
            continue;

        int dist;
        if (pos.first > tmp) {
            dist = pos.first - tmp;
            pos.first -= dist;
            pos.second -= dist;
        } else {
            dist = tmp - pos.second;
            pos.first += dist;
            pos.second += dist;
        }

        movedSum += dist;
    }

    cout << movedSum << "\n";

    return 0;
}