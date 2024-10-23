#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

string S, T;

bool IsConvertable()
{
    bool ret = false;

    while (true)
    {
        if (T[T.length() - 1] == 'A')
        {
            T.pop_back();
        }
        else
        {
            T.pop_back();
            reverse(T.begin(), T.end());
        }

        if (S.length() == T.length())
        {
            if (S == T)
            {
                ret = true;
            }
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

    cin >> S;
    cin >> T;

    if (IsConvertable())
    {
        cout << "1\n";
    }
    else
    {
        cout << "0\n";
    }

    return 0;
}