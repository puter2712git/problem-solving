#include <iostream>

using namespace std;

string str;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> str;

    int joiCount = 0;
    int ioiCount = 0;

    for (int i = 0; i < (int)str.length() - 2; i++)
    {
        if (str.substr(i, 3) == "JOI")
        {
            joiCount++;
        }
        else if (str.substr(i, 3) == "IOI")
        {
            ioiCount++;
        }
    }

    cout << joiCount << "\n";
    cout << ioiCount << "\n";

    return 0;
}