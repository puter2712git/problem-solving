#include <iostream>

using namespace std;

int dartScores[20];

double GetAliceScore(int targetIndex)
{
    int tmp = dartScores[targetIndex];
    if (targetIndex == 0)
    {
        tmp += dartScores[19];
        tmp += dartScores[1];
    }
    else if (targetIndex == 19)
    {
        tmp += dartScores[0];
        tmp += dartScores[18];
    }
    else
    {
        tmp += dartScores[targetIndex - 1];
        tmp += dartScores[targetIndex + 1];
    }

    return tmp / 3.0;
}

double GetBobScore()
{
    return 10.5;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int targetIndex;
    for (int i = 0; i < 20; i++)
    {
        cin >> dartScores[i];
        if (dartScores[i] == 20)
        {
            targetIndex = i;
        }
    }

    double alice = GetAliceScore(targetIndex);
    double bob = GetBobScore();

    if (alice > bob)
    {
        cout << "Alice\n";
    }
    else if (alice < bob)
    {
        cout << "Bob\n";
    }
    else
    {
        cout << "Tie\n";
    }

    return 0;
}