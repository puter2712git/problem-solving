#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    vector<long long> roadLengths;
    vector<long long> costs;

    int currentCost;
    long long totalCost = 0;

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        long long len;
        cin >> len;
        roadLengths.push_back(len);
    }
    for (int i = 0; i < n; i++) {
        long long cost;
        cin >> cost;
        costs.push_back(cost);
    }

    currentCost = costs[0];
    totalCost += currentCost * roadLengths[0];

    for (int i = 1; i < n - 1; i++) {
        if (currentCost > costs[i]) {
            currentCost = costs[i];
        }
        totalCost += currentCost * roadLengths[i];
    }

    cout << totalCost << "\n";
    return 0;
}