#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int GetCount(vector<int> &ids, int target)
{
    int begin = 0;
    int end = ids.size() - 1;
    int sum = 0;

    int count = 0;

    while (begin < end)
    {
        sum = ids[begin] + ids[end];

        if (sum < target)
        {
            begin++;
        }
        else if (sum > target)
        {
            end--;
        }
        else
        {
            count++;
            begin++;
            end--;
        }
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ingredientLength;
    int target;
    vector<int> ids;

    cin >> ingredientLength;
    cin >> target;
    for (int i = 0; i < ingredientLength; i++)
    {
        int tmp;
        cin >> tmp;
        ids.push_back(tmp);
    }

    sort(ids.begin(), ids.end(), less<int>());

    cout << GetCount(ids, target) << "\n";

    return 0;
}