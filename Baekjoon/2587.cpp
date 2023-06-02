#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_average(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }

    return sum / nums.size();
}

int get_median(vector<int> &nums)
{
    int size = nums.size();
    int ret = 0;

    if (size % 2 == 0)
    {
        ret = (nums[size / 2 - 1] + nums[size / 2]) / 2;
    }
    else
    {
        ret = nums[size / 2];
    }

    return ret;
}

int main()
{
    int num;
    vector<int> nums;

    for (int i = 0; i < 5; i++)
    {
        cin >> num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    cout << get_average(nums) << "\n";
    cout << get_median(nums) << "\n";

    return 0;
}