#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int H, N;
    cin >> H >> N;

    vector<vector<long long>> ways(31, vector<long long>(31, 0));

    for (int i = 0; i <= 30; i++) {
        for (int j = 0; j <= 30; j++) {
            if (j < i) continue;
            if (i == 0 || j == 0) {
                ways[i][j] = 1;
                continue;
            }

            ways[i][j] = ways[i - 1][j] + ways[i][j - 1];
        }
    }

    int diff = abs(H - N);
    cout << ways[diff][diff] << "\n";

    return 0;
}