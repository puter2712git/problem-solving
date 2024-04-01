#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int bookLength;
    map<string, int> bookMap;

    cin >> bookLength;
    for (int i = 0; i < bookLength; i++) {
        string book;
        cin >> book;

        if (bookMap.find(book) == bookMap.end()) {
            bookMap.insert({ book, 1 });
        } else {
            bookMap[book]++;
        }
    }

    string maxKey = bookMap.begin()->first;
    int maxValue = bookMap.begin()->second;

    for (auto iter = bookMap.begin(); iter != bookMap.end(); iter++) {
        if (maxValue < iter->second) {
            maxKey = iter->first;
            maxValue = iter->second;
        }
    }

    cout << maxKey << "\n";

    return 0;
}