#include <iostream>
#include <vector>

using namespace std;

string str1, str2;

void Setup()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Input()
{
    cin >> str1;
    cin >> str2;
}

void Solve()
{
    int len1 = str1.length();
    int len2 = str2.length();
    vector<vector<int>> LCS(len1 + 1, vector<int>(len2 + 1, 0));

    int maxSubsequenceLength = 0;

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
                maxSubsequenceLength = max(maxSubsequenceLength, LCS[i][j]);
            }
        }
    }

    cout << maxSubsequenceLength << "\n";
}

int main()
{
    Setup();
    Input();
    Solve();

    return 0;
}