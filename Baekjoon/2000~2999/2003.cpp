#include <iostream>
#include <vector>

using namespace std;

int GetCasesCount(vector<int>& partialSums, int target)
{
    int begin = -1, end = 0;
    int sum = 0;

    int count = 0;

    while (end < partialSums.size()) {
        if (begin < 0) {
            sum = partialSums[end];
        } else {
            sum = partialSums[end] - partialSums[begin];
        }

        if (sum == target) {
            count++;
            end++;
        } else if (sum > target) {
            begin++;
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

    int numLength, target;
    vector<int> numbers;
    vector<int> partialSums;

    cin >> numLength >> target;
    for (int i = 0; i < numLength; i++) {
        int tmp;
        cin >> tmp;
        numbers.push_back(tmp);

        if (i == 0) {
            partialSums.push_back(numbers[i]);
        } else {
            partialSums.push_back(partialSums[i - 1] + numbers[i]);
        }
    }

    cout << GetCasesCount(partialSums, target) << "\n";

    return 0;
}