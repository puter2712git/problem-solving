#include <iostream>
#include <vector>

using namespace std;

void MakeDPList(int maxLen, vector<bool>& out)
{
    out.clear();
    out.push_back(false);
    out.push_back(false);
    out.push_back(true);
    out.push_back(false);

    for (int i = 4; i <= maxLen; i++) {
        if (!out[i - 1] || !out[i - 3]) {
            out.push_back(true);
        } else {
            out.push_back(false);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int stoneCount;
    vector<bool> isFirstWin;

    cin >> stoneCount;
    MakeDPList(stoneCount, isFirstWin);

    if (isFirstWin[stoneCount]) {
        cout << "SK"
             << "\n";
    } else {
        cout << "CY"
             << "\n";
    }

    return 0;
}