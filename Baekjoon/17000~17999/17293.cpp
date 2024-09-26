#include <iostream>

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    int bottleCount = N;

    while (N > 0)
    {
        if (N == 1)
        {
            cout << N << " bottle of beer on the wall, " << N << " bottle of beer.\n";
        }
        else
        {
            cout << N << " bottles of beer on the wall, " << N << " bottles of beer.\n";
        }
        N--;

        if (N == 0)
        {
            break;
        }
        if (N == 1)
        {
            cout << "Take one down and pass it around, " << N << " bottle of beer on the wall.\n";
        }
        else
        {
            cout << "Take one down and pass it around, " << N << " bottles of beer on the wall.\n";
        }
        cout << "\n";
    }

    cout << "Take one down and pass it around, no more bottles of beer on the wall.\n";
    cout << "\n";

    cout << "No more bottles of beer on the wall, no more bottles of beer.\n";
    if (bottleCount == 1)
    {
        cout << "Go to the store and buy some more, " << bottleCount << " bottle of beer on the wall.\n";
    }
    else
    {
        cout << "Go to the store and buy some more, " << bottleCount << " bottles of beer on the wall.\n";
    }

    return 0;
}