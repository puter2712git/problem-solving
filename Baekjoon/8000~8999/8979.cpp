#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Nation {
    int index;
    int gold;
    int silver;
    int bronze;

    bool operator>(const Nation& n) const
    {
        if (gold != n.gold) {
            return gold > n.gold;
        }

        if (silver != n.silver) {
            return silver > n.silver;
        }

        return bronze > n.bronze;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int nationCount;
    int target;
    vector<Nation> nations;

    cin >> nationCount >> target;
    for (int i = 0; i < nationCount; i++) {
        int nationIndex, goldCount, silverCount, bronzeCount;
        cin >> nationIndex >> goldCount >> silverCount >> bronzeCount;
        nations.push_back({
            nationIndex,
            goldCount,
            silverCount,
            bronzeCount,
        });
    }

    sort(nations.begin(), nations.end(), greater<>());

    int rank = 1, sameCount = 0;
    for (int i = 0; i < nationCount; i++) {
        if (i > 0 && (nations[i].gold != nations[i - 1].gold || nations[i].silver != nations[i - 1].silver || nations[i].bronze != nations[i - 1].bronze)) {
            rank += sameCount;
            sameCount = 0;
        }

        if (nations[i].index == target)
            break;

        sameCount++;
    }

    cout << rank << "\n";

    return 0;
}