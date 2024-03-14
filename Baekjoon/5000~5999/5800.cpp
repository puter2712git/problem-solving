#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int GetLargestGap(vector<int>& scores)
{
    int maxGap = abs(scores[1] - scores[0]);

    for (int i = 1; i < scores.size() - 1; i++) {
        if (maxGap < abs(scores[i + 1] - scores[i])) {
            maxGap = abs(scores[i + 1] - scores[i]);
        }
    }

    return maxGap;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int classCount;

    cin >> classCount;

    for (int i = 0; i < classCount; i++) {
        int studentCount;
        vector<int> scores;

        cin >> studentCount;
        for (int j = 0; j < studentCount; j++) {
            int tmp;
            cin >> tmp;
            scores.push_back(tmp);
        }

        sort(scores.begin(), scores.end());

        cout << "Class " << i + 1
             << "\n"
             << "Max " << scores[scores.size() - 1] << ", Min " << scores[0] << ", Largest gap " << GetLargestGap(scores) << "\n";
    }

    return 0;
}