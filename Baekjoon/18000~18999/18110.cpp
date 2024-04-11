#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int GetTrimmedMean(vector<int> &opinions)
{
    int trimLength = round(opinions.size() * 0.15);
    int sum = 0;

    for (int i = trimLength; i < opinions.size() - trimLength; i++)
    {
        sum += opinions[i];
    }
    sum = round((float)sum / (opinions.size() - trimLength * 2));

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int opinionLength;
    vector<int> opinions;

    cin >> opinionLength;
    for (int i = 0; i < opinionLength; i++)
    {
        int opinion;
        cin >> opinion;
        opinions.push_back(opinion);
    }

    if (opinionLength == 0)
    {
        cout << 0 << "\n";
        return 0;
    }

    sort(opinions.begin(), opinions.end(), less<int>());

    cout << GetTrimmedMean(opinions) << "\n";

    return 0;
}