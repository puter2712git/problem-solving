#include <iostream>
#include <vector>

using namespace std;

int T;
vector<string> words;

void Setup()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Input()
{
    cin >> T;
    words = vector<string>(T);

    for (int i = 0; i < T; i++)
    {
        cin >> words[i];
    }
}

int CheckPalindrome(const string &str, int beginIndex, int endIndex, int failCount)
{
    while (beginIndex < endIndex)
    {
        if (str[beginIndex] != str[endIndex])
        {
            if (failCount == 0)
            {
                if (CheckPalindrome(str, beginIndex + 1, endIndex, 1) == 0 || CheckPalindrome(str, beginIndex, endIndex - 1, 1) == 0)
                {
                    return 1;
                }
                else
                {
                    return 2;
                }
            }
            else
            {
                return 2;
            }
        }
        else
        {
            beginIndex++;
            endIndex--;
        }
    }

    return 0;
}

void Solve()
{
    for (const string &str : words)
    {
        cout << CheckPalindrome(str, 0, str.length() - 1, 0) << "\n";
    }
}

int main()
{
    Setup();
    Input();
    Solve();

    return 0;
}