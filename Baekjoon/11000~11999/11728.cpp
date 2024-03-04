#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int arrALen, arrBLen;
    vector<int> arr;

    cin >> arrALen >> arrBLen;
    for (int i = 0; i < arrALen + arrBLen; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < arrALen + arrBLen; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}