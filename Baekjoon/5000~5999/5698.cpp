#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void Parse(vector<string> &words, string &str)
{
    words = vector<string>(0);
    stringstream ss(str);

    string tmp;
    while (ss >> tmp)
    {
        words.push_back(tmp);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    vector<string> words;
    while (getline(cin, str))
    {
        if (str == "*")
        {
            break;
        }

        Parse(words, str);
        char tmp = tolower(words[0][0]);

        bool isTautogram = true;
        for (int i = 1; i < words.size(); i++)
        {
            if (tmp != tolower(words[i][0]))
            {
                isTautogram = false;
                break;
            }
        }

        if (isTautogram)
        {
            cout << "Y\n";
        }
        else
        {
            cout << "N\n";
        }
    }

    return 0;
}