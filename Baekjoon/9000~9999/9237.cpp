#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int seedlingCount;
    vector<int> growthDays;

    cin >> seedlingCount;
    for (int i = 0; i < seedlingCount; i++) {
        int tmp;
        cin >> tmp;
        growthDays.push_back(tmp);
    }

    sort(growthDays.begin(), growthDays.end(), greater<int>());
    for (int i = 0; i < seedlingCount; i++) {
        growthDays[i] += i;
    }

    cout << *max_element(growthDays.begin(), growthDays.end()) + 2 << "\n";

    return 0;
}