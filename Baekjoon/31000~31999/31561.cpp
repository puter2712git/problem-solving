#include <iostream>

using namespace std;

float M;

void Setup()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << fixed;
    cout.precision(1);
}

void Input()
{
    cin >> M;
}

void Solve()
{
    float answer;

    if (M > 30)
    {
        answer = 15 + (M - 30) * 1.5;
    }
    else
    {
        answer = M / 2;
    }

    cout << answer;
}

int main()
{
    Setup();
    Input();
    Solve();

    return 0;
}