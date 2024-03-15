#include <iostream>

using namespace std;

bool IsVowel(char element)
{
    return element == 'a' || element == 'e' || element == 'i' || element == 'o' || element == 'u';
}

bool CheckFirstRestriction(string& password)
{
    for (int i = 0; i < password.length(); i++) {
        if (IsVowel(password[i])) {
            return true;
        }
    }

    return false;
}

bool CheckSecondRestriction(string& password)
{
    bool isVowel = IsVowel(password[0]);
    int count = 1;

    for (int i = 1; i < password.length(); i++) {
        if (IsVowel(password[i]) && isVowel) {
            count++;
        } else if (!IsVowel(password[i]) && !isVowel) {
            count++;
        } else {
            isVowel = IsVowel(password[i]);
            count = 1;
        }

        if (count >= 3) {
            return false;
        }
    }

    return true;
}

bool CheckThirdRestriction(string& password)
{
    char latestElement = password[0];

    for (int i = 1; i < password.length(); i++) {
        if (password[i] == latestElement && latestElement != 'e' && latestElement != 'o') {
            return false;
        }

        latestElement = password[i];
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true) {
        string password;
        cin >> password;

        if (password == "end") {
            break;
        }

        if (CheckFirstRestriction(password) && CheckSecondRestriction(password) && CheckThirdRestriction(password)) {
            cout << "<" << password << "> is acceptable.\n";
        } else {
            cout << "<" << password << "> is not acceptable.\n";
        }
    }

    return 0;
}