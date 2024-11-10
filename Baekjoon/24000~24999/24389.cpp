#include <iostream>

using namespace std;

int N;

void Setup()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Input()
{
    cin >> N;
}

void Solve()
{
    int count = 0;
    int bit = 1;

    N = N ^ (~N + 1);

    for (int i = 0; i < 32; i++)
    {
        if (N & bit)
        {
            count++;
        }
        bit <<= 1;
    }

    cout << count << "\n";
}

int main()
{
    Setup();
    Input();
    Solve();

    return 0;
}