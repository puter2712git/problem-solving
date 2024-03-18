#include <iostream>
#include <vector>

using namespace std;

void FillPascalTriangle(vector<vector<int>>& out, int n)
{
    out.clear();
    out = vector<vector<int>>(n + 1, vector<int>(n + 1));

    out[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                out[i][j] = 1;
            } else if (j == i) {
                out[i][j] = 1;
            } else {
                out[i][j] = out[i - 1][j - 1] + out[i - 1][j];
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> pascalTriangle;
    FillPascalTriangle(pascalTriangle, n);

    cout << pascalTriangle[n - 1][k - 1] << "\n";

    return 0;
}