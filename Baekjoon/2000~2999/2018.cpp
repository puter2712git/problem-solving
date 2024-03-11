#include <iostream>
#include <vector>

using namespace std;

int GetSumBetweenTwoPointers(int start, int end)
{
    int sum = 0;

    for (int i = start; i <= end; i++) {
        sum += i;
    }

    return sum;
}

int GetCountOfWays(int target)
{
    int count = 0;
    int start = 1, end = 1;

    while (end <= target) {
        int sum = GetSumBetweenTwoPointers(start, end);

        if (sum == target) {
            count++;
            end++;
        } else if (sum > target) {
            start++;
        } else {
            end++;
        }
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;

    cin >> n;

    cout << GetCountOfWays(n) << "\n";

    return 0;
}