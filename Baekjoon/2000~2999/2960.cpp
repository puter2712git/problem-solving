#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int checkCount = 0;

    vector<bool> checked = vector<bool>(n + 1, false);
    checked[0] = true;
    checked[1] = true;

    for (int i = 2; i <= n; i++) {
        if (checked[i])
            continue;

        for (int j = i; j <= n; j++) {
            if (checked[j])
                continue;

            if (j % i == 0) {
                checked[j] = true;
                checkCount++;

                if (checkCount == k) {
                    cout << j << "\n";
                    return 0;
                }
            }
        }
    }
}