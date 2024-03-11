#include <iostream>
#include <vector>

using namespace std;

void CreateDP(vector<pair<int, int>>& out, int target)
{
    out.clear();
    out = vector<pair<int, int>>(target + 1);

    out[0] = { 1, 0 };

    for (int i = 1; i <= target; i++) {
        int a = out[i - 1].first;
        int b = out[i - 1].second;

        out[i] = { b, a + b };
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int k;
    vector<pair<int, int>> dpList;

    cin >> k;

    CreateDP(dpList, k);

    cout << dpList[k].first << " " << dpList[k].second << "\n";

    return 0;
}