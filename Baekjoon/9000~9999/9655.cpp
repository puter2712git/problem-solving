#include <iostream>
#include <vector>

using namespace std;

void MakeDPList(vector<short>& out, int target)
{
    out = vector<short>(target + 1);
    out[0] = 0;
    out[1] = 0;
    out[2] = 1;
    out[3] = 0;

    for (int i = 4; i <= target; i++) {
        if (out[i - 1] == 0 || out[i - 3] == 0) {
            out[i] = 1;
        } else {
            out[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int stoneCount;
    vector<short> winnerList;
    cin >> stoneCount;

    MakeDPList(winnerList, stoneCount);

    if (winnerList[stoneCount] == 0) {
        cout << "SK"
             << "\n";
    } else {
        cout << "CY"
             << "\n";
    }

    return 0;
}