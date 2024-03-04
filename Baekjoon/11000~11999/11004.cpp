#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int numCount, targetIndex;
    vector<int> numbers;

    cin >> numCount >> targetIndex;
    for (int i = 0; i < numCount; i++) {
        int tmp;
        cin >> tmp;
        numbers.push_back(tmp);
    }

    sort(numbers.begin(), numbers.end());

    cout << numbers[targetIndex - 1] << "\n";

    return 0;
}