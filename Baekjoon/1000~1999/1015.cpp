#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int arrLength;
    vector<int> arr;
    vector<int> sortedArr;
    vector<int> indexArr;

    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
        sortedArr.push_back(tmp);
    }
    indexArr = vector<int>(arrLength);

    sort(sortedArr.begin(), sortedArr.end(), less<int>());
    sortedArr.erase(unique(sortedArr.begin(), sortedArr.end()), sortedArr.end());

    int index = 0;
    for (int i = 0; i < sortedArr.size(); i++)
    {
        int num = sortedArr[i];
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] == num)
            {
                indexArr[j] = index++;
            }
        }
    }

    for (int i = 0; i < indexArr.size(); i++)
    {
        cout << indexArr[i] << "\n";
    }

    return 0;
}