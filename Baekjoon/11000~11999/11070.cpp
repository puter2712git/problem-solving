#include <iostream>
#include <vector>

using namespace std;

struct TeamInfo
{
    int score;
    int loseScore;
};

int T;

double GetPytExpectation(TeamInfo teamInfo)
{
    if (teamInfo.score == 0 && teamInfo.loseScore == 0)
        return 0;

    double ret = (double)(teamInfo.score * teamInfo.score) / (teamInfo.score * teamInfo.score + teamInfo.loseScore * teamInfo.loseScore);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;

        vector<TeamInfo> teams(n + 1);

        for (int i = 0; i < m; i++)
        {
            int a, b, p, q;
            cin >> a >> b >> p >> q;

            teams[a].score += p;
            teams[a].loseScore += q;

            teams[b].score += q;
            teams[b].loseScore += p;
        }

        double maxPyt = GetPytExpectation(teams[1]);
        double minPyt = GetPytExpectation(teams[1]);

        for (int i = 2; i <= n; i++)
        {
            double currPyt = GetPytExpectation(teams[i]);
            maxPyt = max<double>(maxPyt, currPyt);
            minPyt = min<double>(minPyt, currPyt);
        }

        cout << (int)(maxPyt * 1000) << "\n";
        cout << (int)(minPyt * 1000) << "\n";
    }

    return 0;
}