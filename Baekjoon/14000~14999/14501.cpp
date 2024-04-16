#include <iostream>
#include <vector>

using namespace std;

struct Work
{
    int day;
    int money;
};

vector<int> GetMaxMoneyList(vector<Work> &works, int dayLength)
{
    vector<int> ret(dayLength + 1);

    for (int i = 0; i < dayLength; i++)
    {
        for (int j = works[i].day + i; j <= dayLength; j++)
        {
            if (ret[j] < ret[i] + works[i].money)
            {
                ret[j] = ret[i] + works[i].money;
            }
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int dayLength;
    cin >> dayLength;

    vector<Work> works;

    for (int i = 0; i < dayLength; i++)
    {
        int day;
        int money;
        cin >> day >> money;

        works.push_back({day, money});
    }

    auto maxMoneyList = GetMaxMoneyList(works, dayLength);

    cout << maxMoneyList[dayLength] << "\n";

    return 0;
}