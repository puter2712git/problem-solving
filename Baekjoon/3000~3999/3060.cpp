#include <iostream>
#include <algorithm>

using namespace std;

int T;

void Setup()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Input()
{
    cin >> T;
}

void Solve()
{
    while (T--)
    {
        int N;
        cin >> N;

        int foodSum = 0;
        int food;
        for (int i = 0; i < 6; i++)
        {
            cin >> food;
            foodSum += food;
        }
        int count = 1;

        while (N >= foodSum)
        {
            count++;
            foodSum *= 4;
        }

        cout << count << "\n";
    }
}

int main()
{
    Setup();
    Input();
    Solve();

    return 0;
}