#include <iostream>
#include <queue>

using namespace std;

int n, m;
priority_queue<long long, vector<long long>, greater<long long>> a;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    long long num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        a.push(num);
    }

    for (int i = 0; i < m; i++)
    {
        long long num1 = a.top();
        a.pop();
        long long num2 = a.top();
        a.pop();

        long long sumOfNum = num1 + num2;
        a.push(sumOfNum);
        a.push(sumOfNum);
    }

    long long result = 0;
    while (!a.empty())
    {
        long long tmp = a.top();
        a.pop();
        result += tmp;
    }

    cout << result << "\n";

    return 0;
}