#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void Convert(string& number)
{
    int sum = 0;

    for (int i = 0; i < number.length(); i++) {
        sum += number[i] - '0';
    }

    number = to_string(sum);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string number;
    int convertCount = 0;

    cin >> number;

    while (number.length() > 1) {
        convertCount++;
        Convert(number);
    }

    cout << convertCount << "\n";
    if (stoi(number) % 3 == 0) {
        cout << "YES"
             << "\n";
    } else {
        cout << "NO"
             << "\n";
    }

    return 0;
}