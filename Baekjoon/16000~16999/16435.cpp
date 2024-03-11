#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int fruitCount, tall;
    vector<int> fruits;

    cin >> fruitCount >> tall;
    for (int i = 0; i < fruitCount; i++) {
        int tmp;
        cin >> tmp;
        fruits.push_back(tmp);
    }

    sort(fruits.begin(), fruits.end(), greater<int>());

    while (fruits.size()) {
        if (tall >= fruits.back()) {
            tall++;
            fruits.pop_back();
        } else {
            break;
        }
    }

    cout << tall << "\n";

    return 0;
}