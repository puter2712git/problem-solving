#include <iostream>
#include <map>

using namespace std;

const map<char, char> char_map = {
    { '1', '`' },
    { '2', '1' },
    { '3', '2' },
    { '4', '3' },
    { '5', '4' },
    { '6', '5' },
    { '7', '6' },
    { '8', '7' },
    { '9', '8' },
    { '0', '9' },
    { '-', '0' },
    { '=', '-' },

    { 'W', 'Q' },
    { 'E', 'W' },
    { 'R', 'E' },
    { 'T', 'R' },
    { 'Y', 'T' },
    { 'U', 'Y' },
    { 'I', 'U' },
    { 'O', 'I' },
    { 'P', 'O' },
    { '[', 'P' },
    { ']', '[' },
    { '\\', ']' },

    { 'S', 'A' },
    { 'D', 'S' },
    { 'F', 'D' },
    { 'G', 'F' },
    { 'H', 'G' },
    { 'J', 'H' },
    { 'K', 'J' },
    { 'L', 'K' },
    { ';', 'L' },
    { '\'', ';' },
    { 'X', 'Z' },
    { 'C', 'X' },
    { 'V', 'C' },
    { 'B', 'V' },
    { 'N', 'B' },
    { 'M', 'N' },
    { ',', 'M' },
    { '.', ',' },
    { '/', '.' },
};

string convert_text(string& text)
{
    string ret = text;
    for (int i = 0; i < ret.length(); i++) {
        if (char_map.find(ret[i]) != char_map.end()) {
            ret[i] = char_map.at(ret[i]);
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string text;
    while (getline(cin, text)) {
        cout << convert_text(text) << "\n";
    }

    return 0;
}