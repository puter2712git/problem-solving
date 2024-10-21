#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void Parse(vector<string> &out, string &line)
{
    string tmp;
    stringstream ss(line);
    while (ss >> tmp)
    {
        out.push_back(tmp);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<string>> lines;
    string line;
    while (getline(cin, line))
    {
        vector<string> words;
        Parse(words, line);
        lines.push_back(words);
    }

    int lineLength = lines.size();
    vector<string> answer(lineLength, "");
    int wordIndex = 0;
    int maxWordIndex = 0;
    for (int i = 0; i < lineLength; i++)
    {
        maxWordIndex = max<int>(lines[i].size(), maxWordIndex);
    }
    while (true)
    {
        int maxWordLength = 0;
        for (int i = 0; i < lineLength; i++)
        {
            if (lines[i].size() <= wordIndex)
                continue;

            maxWordLength = max<int>(maxWordLength, lines[i][wordIndex].length());
        }

        for (int i = 0; i < lineLength; i++)
        {
            if (lines[i].size() <= wordIndex)
                continue;

            int currWordLength = lines[i][wordIndex].size();
            answer[i] += lines[i][wordIndex];
            for (int j = currWordLength; j < maxWordLength; j++)
            {
                answer[i] += ' ';
            }

            answer[i] += ' ';
        }

        wordIndex++;
        if (wordIndex > maxWordIndex)
            break;
    }

    for (string &str : answer)
    {
        while (str.back() == ' ')
        {
            str.pop_back();
        }
        cout << str << "\n";
    }

    return 0;
}