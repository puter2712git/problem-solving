#include <algorithm>
#include <iostream>

using namespace std;

bool CanMake(string& number)
{
    // Check is 0 included.
    if (number[number.length() - 1] != '0') {
        return false;
    }

    // Check is multiple of 3.
    int sum = 0;
    for (char element : number) {
        sum += element - '0';
    }
    if (sum % 3 != 0) {
        return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string num;
    cin >> num;

    sort(num.begin(), num.end(), greater<char>());

    if (CanMake(num)) {
        cout << num << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}