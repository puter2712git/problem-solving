#include <iostream>
#include <vector>

using namespace std;

vector<long long> dpList;

void CreateDP(int target)
{
    dpList.clear();
    dpList = vector<long long>(target + 1);

    dpList[0] = 0;
    dpList[1] = 1;
    dpList[2] = 1;

    for (int i = 3; i <= target; i++) {
        dpList[i] = dpList[i - 2] + dpList[i - 1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tileCount;

    cin >> tileCount;

    CreateDP(tileCount);

    cout << dpList[tileCount] * 2 + (dpList[tileCount] + dpList[tileCount - 1]) * 2 << "\n";

    return 0;
}