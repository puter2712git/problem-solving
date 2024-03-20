#include <iostream>
#include <vector>

using namespace std;

vector<int> GetArrayByRule(int start, int second)
{
    vector<int> numbers = { start, second };
    int curr = 1;

    while (true) {
        int result = numbers[curr - 1] - numbers[curr];
        if (result < 0) {
            break;
        } else {
            numbers.push_back(result);
        }

        curr++;
    }

    return numbers;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int number;
    vector<int> maxArr;

    cin >> number;

    for (int i = 1; i <= number; i++) {
        vector<int> tmp = GetArrayByRule(number, i);

        if (maxArr.size() < tmp.size()) {
            maxArr = tmp;
        }
    }

    cout << maxArr.size() << "\n";
    for (int i = 0; i < maxArr.size(); i++) {
        cout << maxArr[i] << " ";
    }
    cout << "\n";

    return 0;
}