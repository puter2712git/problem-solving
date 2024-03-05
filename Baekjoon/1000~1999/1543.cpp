#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string sentence;
    string word;

    getline(cin, sentence);
    getline(cin, word);

    int findPos = 0;
    int findCount = 0;

    while (true) {
        size_t pos = sentence.find(word, findPos);
        if (pos == string::npos) {
            break;
        }

        findPos = pos + word.length();
        findCount++;
    }

    cout << findCount << "\n";

    return 0;
}