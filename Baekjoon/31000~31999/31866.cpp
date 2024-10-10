#include <iostream>

using namespace std;

bool IsInvalid(int n)
{
    return n != 0 && n != 2 && n != 5;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;
    cin >> a >> b;

    if (IsInvalid(a))
    {
        if (IsInvalid(b))
        {
            cout << "=\n";
        }
        else
        {
            cout << "<\n";
        }
    }
    else
    {
        if (IsInvalid(b))
        {
            cout << ">\n";
        }
        else
        {
            if (a == 0)
            {
                if (b == 0)
                {
                    cout << "=\n";
                }
                else if (b == 2)
                {
                    cout << ">\n";
                }
                else if (b == 5)
                {
                    cout << "<\n";
                }
            }
            else if (a == 2)
            {
                if (b == 0)
                {
                    cout << "<\n";
                }
                else if (b == 2)
                {
                    cout << "=\n";
                }
                else
                {
                    cout << ">\n";
                }
            }
            else if (a == 5)
            {
                if (b == 0)
                {
                    cout << ">\n";
                }
                else if (b == 2)
                {
                    cout << "<\n";
                }
                else
                {
                    cout << "=\n";
                }
            }
        }
    }

    return 0;
}