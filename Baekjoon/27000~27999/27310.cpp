#include <iostream>

using namespace std;

string imoji;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> imoji;

    int colonCount = 0;
    int underbarCount = 0;

    for (char& ch : imoji)
    {
        if (ch == ':')
        {
            colonCount += 1;
        }
        else if (ch == '_')
        {
            underbarCount += 1;
        }
    }

    int score = imoji.length() + colonCount + underbarCount * 5;
    
    cout << score << "\n";

    return 0;
}