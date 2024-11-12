#include <iostream>
#include <stack>

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
    stack<int> s;
    long long count = 0;

    int height;
    for (int i = 0; i < N; i++)
    {
        cin >> height;

        if (s.empty())
        {
            s.push(height);
            continue;
        }

        while (!s.empty() && s.top() <= height)
        {
            s.pop();
        }

        count += s.size();
        s.push(height);
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