#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, k;
    int x;

    vector<int> scores;

    cin >> N >> k;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        scores.push_back(x);
    }

    sort(scores.begin(), scores.end());

    cout << scores[scores.size() - k] << "\n";

    return 0;
}