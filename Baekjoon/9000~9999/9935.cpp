#include <iostream>
#include <stack>

using namespace std;

string str;
string bomb;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> str;
    cin >> bomb;

    string tmp;

    for (char ch : str)
    {
        tmp.push_back(ch);

        if (tmp.length() < bomb.length())
            continue;

        if (tmp.substr(tmp.length() - bomb.length()) == bomb)
        {
            for (int i = 0; i < (int)bomb.length(); i++)
            {
                tmp.pop_back();
            }
        }
    }

    if (tmp.length() == 0)
    {
        cout << "FRULA\n";
    }
    else
    {
        cout << tmp << "\n";
    }

    return 0;
}