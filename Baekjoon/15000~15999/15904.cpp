#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool IsAbbreviation(string& str)
{
    stack<char> ucpc;
    ucpc.push('C');
    ucpc.push('P');
    ucpc.push('C');
    ucpc.push('U');

    for (char element : str) {
        if (element == ucpc.top()) {
            ucpc.pop();

            if (ucpc.size() == 0) {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    getline(cin, str);

    if (IsAbbreviation(str)) {
        cout << "I love UCPC"
             << "\n";
    } else {
        cout << "I hate UCPC"
             << "\n";
    }

    return 0;
}