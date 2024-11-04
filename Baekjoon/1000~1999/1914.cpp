#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int N;

void Input()
{
    cin >> N;
}

void Hanoi(int num, int from, int by, int to)
{
    if (num == 1)
    {
        cout << from << " " << to << "\n";
        return;
    }

    Hanoi(num - 1, from, to, by);
    cout << from << " " << to << "\n";
    Hanoi(num - 1, by, from, to);
}

void Solve()
{
    string processCount = to_string(pow(2, N));
    int dotIndex = processCount.find('.');
    processCount = processCount.substr(0, dotIndex);
    processCount[processCount.length() - 1]--;

    cout << processCount << "\n";

    if (N <= 20)
    {
        Hanoi(N, 1, 2, 3);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solve();

    return 0;
}