#include <iostream>
#include <stack>

using namespace std;

bool IsGood(string& word)
{
    stack<char> st;

    for (char ch : word) {
        if (st.empty()) {
            st.push(ch);
        } else {
            if (st.top() == ch) {
                st.pop();
            } else {
                st.push(ch);
            }
        }
    }

    return st.empty();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int wordLength;
    cin >> wordLength;

    int count = 0;

    for (int i = 0; i < wordLength; i++) {
        string word;
        cin >> word;

        if (IsGood(word)) {
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}