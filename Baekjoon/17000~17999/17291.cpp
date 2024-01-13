#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long N;
    cin >> N;

    vector<long long> bugs;
    bugs.push_back(1);
    bugs.push_back(1);

    for (int i = 2; i <= N; i++) {
        bugs.push_back(bugs[i - 1] * 2);

        if (i == 4) bugs[i] = 7;

        if (i < 5) continue;

        if (i % 2 == 0) {
            bugs[i] -= bugs[i - 4] + bugs[i - 5];
        }
    }

    cout << bugs[N] << "\n";

    return 0;
}