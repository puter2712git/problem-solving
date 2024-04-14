#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int GetNextNumber(int num, int p)
{
    int ret = 0;

    while (num > 0)
    {
        int n = num % 10;
        ret += pow(n, p);
        num /= 10;
    }

    return ret;
}

int GetIndexOfNumber(vector<int> &arr, int num)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int num;
    int p;
    vector<int> nums;

    cin >> num;
    cin >> p;
    nums.push_back(num);

    int index;

    while (true)
    {
        int nextNumber = GetNextNumber(nums.back(), p);
        index = GetIndexOfNumber(nums, nextNumber);

        if (index == -1)
        {
            nums.push_back(nextNumber);
        }
        else
        {
            break;
        }
    }

    cout << index << "\n";

    return 0;
}