#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int ConvertToDecimal(vector<int>& number, int form)
{
    int ret = 0;

    reverse(number.begin(), number.end());

    for (int i = 0; i < number.size(); i++) {
        ret += number[i] * pow(form, i);
    }

    return ret;
}

vector<int> FormalizeDecimal(int decimal, int form)
{
    vector<int> digits;

    while (decimal >= form) {
        digits.push_back(decimal % form);
        decimal = decimal / form;
    }
    digits.push_back(decimal);

    reverse(digits.begin(), digits.end());

    return digits;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int formA, formB;
    int digitCount;
    vector<int> digits;

    cin >> formA >> formB;
    cin >> digitCount;
    for (int i = 0; i < digitCount; i++) {
        int tmp;
        cin >> tmp;
        digits.push_back(tmp);
    }

    int decimal = ConvertToDecimal(digits, formA);
    vector<int> result = FormalizeDecimal(decimal, formB);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}