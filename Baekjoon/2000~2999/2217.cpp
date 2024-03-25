#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ropeCount;
    vector<int> ropeWeights;

    cin >> ropeCount;
    for (int i = 0; i < ropeCount; i++) {
        int tmp;
        cin >> tmp;
        ropeWeights.push_back(tmp);
    }

    sort(ropeWeights.begin(), ropeWeights.end(), greater<int>());

    int maxWeight = ropeWeights[0];
    for (int i = 1; i < ropeCount; i++) {
        if (maxWeight < ropeWeights[i] * (i + 1)) {
            maxWeight = ropeWeights[i] * (i + 1);
        }
    }

    cout << maxWeight << "\n";

    return 0;
}