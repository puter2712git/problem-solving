#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int index = 1;
    while (true)
    {
        int a, b;
        string op;

        cin >> a >> op >> b;

        if (op == ">")
        {
            if (a > b)
            {
                cout << "Case " << index << ": true\n";
            }
            else
            {
                cout << "Case " << index << ": false\n";
            }
        }
        else if (op == ">=")
        {
            if (a >= b)
            {
                cout << "Case " << index << ": true\n";
            }
            else
            {
                cout << "Case " << index << ": false\n";
            }
        }
        else if (op == "<")
        {
            if (a < b)
            {
                cout << "Case " << index << ": true\n";
            }
            else
            {
                cout << "Case " << index << ": false\n";
            }
        }
        else if (op == "<=")
        {
            if (a <= b)
            {
                cout << "Case " << index << ": true\n";
            }
            else
            {
                cout << "Case " << index << ": false\n";
            }
        }
        else if (op == "==")
        {
            if (a == b)
            {
                cout << "Case " << index << ": true\n";
            }
            else
            {
                cout << "Case " << index << ": false\n";
            }
        }
        else if (op == "!=")
        {
            if (a != b)
            {
                cout << "Case " << index << ": true\n";
            }
            else
            {
                cout << "Case " << index << ": false\n";
            }
        }
        else if (op == "E")
        {
            break;
        }

        index++;
    }

    return 0;
}