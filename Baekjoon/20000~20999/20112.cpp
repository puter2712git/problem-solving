#include <iostream>
#include <vector>

using namespace std;

int N;
vector<string> strs;

bool IsSator()
{
    bool ret = true;

    for (int i = 0; i < N; i++)
    {
        string tmp;
        for (int j = 0; j < N; j++)
        {
            tmp.push_back(strs[j][i]);
        }

        if (tmp != strs[i])
        {
            ret = false;
            break;
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    strs = vector<string>(N);

    for (int i = 0; i < N; i++)
    {
        cin >> strs[i];
    }

    if (IsSator())
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}