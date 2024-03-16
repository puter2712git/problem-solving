#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string GetFirstWord(string& word)
{
    vector<string> words;

    for (int i = 1; i < word.length() - 1; i++) {
        for (int j = i + 1; j < word.length(); j++) {
            string tmp[3] = { word.substr(0, i), word.substr(i, j - i), word.substr(j, word.length() - j) };

            for (int k = 0; k < 3; k++) {
                reverse(tmp[k].begin(), tmp[k].end());
            }

            words.push_back(tmp[0] + tmp[1] + tmp[2]);
        }
    }

    sort(words.begin(), words.end());

    return words[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string word;

    cin >> word;

    cout << GetFirstWord(word) << "\n";

    return 0;
}