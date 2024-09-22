#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N;
map<string, vector<string>> mentoList;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string mento, menti;
        cin >> mento >> menti;

        mentoList[mento].push_back(menti);
    }

    for (map<string, vector<string>>::iterator iter = mentoList.begin(); iter != mentoList.end(); iter++)
    {
        sort(iter->second.begin(), iter->second.end(), greater<string>());

        for (string &menti : iter->second)
        {
            cout << iter->first << " " << menti << "\n";
        }
    }

    return 0;
}