#include <iostream>

using namespace std;

int N;
string S;

bool IsANASubString(string &str)
{
    int len = str.length();
    int nCount = 0;

    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'N')
        {
            nCount++;
        }
    }

    return nCount == 1;
}

int FindANACount(string &str)
{
    int ret = 0;

    for (int i = 0; i < (int)str.length(); i++)
    {
        if (str[i] != 'A')
            continue;

        string substr;
        substr.push_back(str[i]);

        bool flag = false;

        for (int j = i + 1; j < (int)str.length(); j++)
        {
            substr.push_back(str[j]);

            if (str[j] == 'A')
            {
                flag = true;
                break;
            }
        }

        if (flag)
        {
            if (IsANASubString(substr))
            {
                ret++;
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

    cin >> N;
    cin >> S;

    cout << FindANACount(S);

    return 0;
}