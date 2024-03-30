#include <iostream>
#include <vector>

using namespace std;

int GetGCD(int a, int b)
{
    if (a % b == 0) {
        return b;
    } else {
        return GetGCD(b, a % b);
    }
}

long long GetSumOfGCD(vector<int>& nums)
{
    long long ret = 0;

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            ret += nums[i] > nums[j] ? GetGCD(nums[i], nums[j]) : GetGCD(nums[j], nums[i]);
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testcase;
    cin >> testcase;

    for (int i = 0; i < testcase; i++) {
        int numLength;
        vector<int> numbers;

        cin >> numLength;
        for (int j = 0; j < numLength; j++) {
            int tmp;
            cin >> tmp;
            numbers.push_back(tmp);
        }

        cout << GetSumOfGCD(numbers) << "\n";
    }

    return 0;
}