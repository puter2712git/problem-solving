#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int day = 0;

    int N, K, A, B;
    cin >> N >> K >> A >> B;

    vector<int> pots(N, K);

    while (true) {
        sort(pots.begin(), pots.end());

        if (pots[0] == 0) break;

        for (int i = 0; i < N; i++) {
            if (i < A) {
                pots[i] += B - 1;
            }
            else {
                pots[i] -= 1;
            }
        }

        day++;
    }

    cout << day << "\n";

    return 0;
}