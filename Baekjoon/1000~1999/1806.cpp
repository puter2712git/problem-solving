#include <iostream>
#include <vector>

using namespace std;

const int INF = (int)1e9;

int N, S;
vector<int> arr;
vector<long long> sumArr;

int GetMinLength()
{
    int beginIndex = 0;
    int endIndex = 1;
    int minLength = INF;

    while (endIndex <= N)
    {
        long long currSum = sumArr[endIndex] - sumArr[beginIndex];

        if (currSum >= S)
        {
            minLength = min<int>(minLength, endIndex - beginIndex);
            beginIndex++;
        }
        else
        {
            endIndex++;
        }
    }

    return minLength == INF ? 0 : minLength;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> S;

    arr = vector<int>(N + 1, 0);
    sumArr = vector<long long>(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        sumArr[i] = sumArr[i - 1] + arr[i];
    }

    cout << GetMinLength() << "\n";

    return 0;
}