#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int number;
    int digit;
    int count = 0;

    cin >> number >> digit;

    char digitChar = '0' + digit;

    for (int i = 1; i <= number; i++) {
        string numString = to_string(i);

        for (int j = 0; j < numString.length(); j++) {
            if (numString[j] == digitChar) {
                count++;
            }
        }
    }

    cout << count << "\n";
    
    return 0;
}