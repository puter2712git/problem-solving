#include <iostream>
#include <vector>

using namespace std;

int GetDecreasedCount(vector<int> &scores)
{
    int prevScore;
    int count = 0;

    for (int i = 0; i < scores.size(); i++)
    {
        if (i == 0)
        {
            prevScore = scores[scores.size() - i - 1];
            continue;
        }

        if (scores[scores.size() - i - 1] >= prevScore)
        {
            count += scores[scores.size() - i - 1] - prevScore + 1;
            scores[scores.size() - i - 1] = prevScore - 1;
        }

        prevScore = scores[scores.size() - i - 1];
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int levelLength;
    vector<int> scores;

    cin >> levelLength;
    for (int i = 0; i < levelLength; i++)
    {
        int score;
        cin >> score;
        scores.push_back(score);
    }

    cout << GetDecreasedCount(scores) << "\n";

    return 0;
}