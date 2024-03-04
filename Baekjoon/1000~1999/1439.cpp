#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    int charCount[2] = { 0 };

    cin >> str;

    char tmp = '\0';
    for (char element : str) {
        if (tmp != element) {
            tmp = element;
            charCount[tmp - '0']++;
        }
    }

    cout << min(charCount[0], charCount[1]) << "\n";

    return 0;
}