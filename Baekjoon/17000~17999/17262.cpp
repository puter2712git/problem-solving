#include <iostream>

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    int s, e;
    int sMax = 0;
    int eMin = 100'001;
    for (int i = 0; i < N; i++)
    {
        cin >> s >> e;
        sMax = max(sMax, s);
        eMin = min(eMin, e);
    }

    cout << max(0, sMax - eMin) << "\n";

    return 0;
}