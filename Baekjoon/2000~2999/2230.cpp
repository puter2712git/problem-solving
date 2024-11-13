#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> A;

void Setup()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Input()
{
    cin >> N >> M;
    A = vector<int>(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }
}

void Solve()
{
    sort(A.begin() + 1, A.end(), less<int>());

    int minDifference = INT_MAX;

    int beginIndex = 1;
    int endIndex = 1;

    while (beginIndex <= N && endIndex <= N)
    {
        int beginElement = A[beginIndex];
        int endElement = A[endIndex];

        int difference = endElement - beginElement;

        if (difference < M)
        {
            endIndex++;
        }
        else
        {
            minDifference = min(minDifference, difference);
            beginIndex++;
        }
    }

    cout << minDifference << "\n";
}

int main()
{
    Setup();
    Input();
    Solve();

    return 0;
}