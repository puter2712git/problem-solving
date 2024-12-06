#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++)
    {
        int pack;
        cin >> pack;

        pq.push(pack);
    }

    vector<int> compareCounts;

    while (pq.size() > 1)
    {
        int pack0 = pq.top();
        pq.pop();

        int pack1 = pq.top();
        pq.pop();

        pq.push(pack0 + pack1);
        compareCounts.push_back(pack0 + pack1);
    }

    int totalCompareCount = 0;
    for (int count : compareCounts)
    {
        totalCompareCount += count;
    }

    cout << totalCompareCount << "\n";

    return 0;
}