#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testcaseLength;
    cin >> testcaseLength;

    for (int i = 0; i < testcaseLength; i++)
    {
        int numLength;
        map<int, int> numMap;

        cin >> numLength;
        for (int j = 0; j < numLength; j++)
        {
            int num;
            cin >> num;
            numMap.insert({num, 0});
        }

        cin >> numLength;
        for (int j = 0; j < numLength; j++)
        {
            int num;
            cin >> num;
            if (numMap.find(num) != numMap.end())
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
    }

    return 0;
}