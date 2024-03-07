#include <iostream>
#include <vector>

using namespace std;

void SetChargeCoinCounts(vector<int>& out, int target)
{
    out.clear();
    out = vector<int>(target + 1);

    for (int i = 0; i <= target; i++) {
        if (i == 0)
            out[0] = -1;
        else if (i == 1)
            out[1] = -1;
        else if (i == 2)
            out[2] = 1;
        else if (i == 3)
            out[3] = -1;
        else if (i == 4)
            out[4] = 2;
        else if (i == 5)
            out[5] = 1;
        else {
            int twoBefore = out[i - 2] + 1;
            int fiveBefore = out[i - 5] + 1;

            if (twoBefore == 0 && fiveBefore == 0) {
                out[i] = -1;
            } else if (twoBefore != 0 && fiveBefore != 0) {
                out[i] = min(twoBefore, fiveBefore);
            } else {
                out[i] = max(twoBefore, fiveBefore);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int charge;
    vector<int> chargeCoinCounts;

    cin >> charge;
    SetChargeCoinCounts(chargeCoinCounts, charge);

    cout << chargeCoinCounts[charge] << "\n";

    return 0;
}