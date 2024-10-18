#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> refCounts;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    refCounts = vector<int>(n);
    for (int i = 0; i < n; i++)
    {
        cin >> refCounts[i];
    }

    sort(refCounts.begin(), refCounts.end(), less<int>());

    int qIndex = n;
    for (int i = 0; i < n; i++)
    {
        if (refCounts[i] >= qIndex)
        {
            break;
        }
        else
        {
            qIndex--;
        }
    }

    cout << qIndex << "\n";

    return 0;
}