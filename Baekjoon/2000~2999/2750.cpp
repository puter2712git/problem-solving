#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int> &nums)
{
    int i, j;
    int len = nums.size();
    int key;

    for (i = 1; i < len; i++)
    {
        key = nums[i];

        for (j = i - 1; j >= 0 && nums[j] > key; j--)
        {
            nums[j + 1] = nums[j];
        }

        nums[j + 1] = key;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int num_count;
    vector<int> nums;

    cin >> num_count;

    for (int i = 0; i < num_count; i++)
    {
        int tmp;
        cin >> tmp;

        nums.push_back(tmp);
    }

    insertion_sort(nums);

    for (int i = 0; i < num_count; i++)
    {
        cout << nums[i] << "\n";
    }

    return 0;
}