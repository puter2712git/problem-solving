#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int numCount;
    vector<int> nums;

    cin >> numCount;
    for (int i = 0; i < numCount; i++) {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }

    sort(nums.begin(), nums.end(), greater<int>());

    for (int i = 0; i < numCount; i++) {
        cout << nums[i] << "\n";
    }

    return 0;
}