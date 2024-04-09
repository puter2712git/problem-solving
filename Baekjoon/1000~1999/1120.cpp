#include <iostream>

using namespace std;

int GetDifference(string &str1, string &str2)
{
    int dlen = str2.length() - str1.length();
    int ret = -1;

    for (int i = 0; i <= dlen; i++)
    {
        int diff = 0;

        for (int j = 0; j < str1.length(); j++)
        {
            if (str1[j] != str2[i + j])
            {
                diff++;
            }
        }

        if (ret == -1 || ret > diff)
        {
            ret = diff;
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string x;
    string y;

    cin >> x >> y;
    int minDiff = GetDifference(x, y);

    cout << minDiff << "\n";

    return 0;
}