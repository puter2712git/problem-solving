#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
int t, r;

int water = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K;
    int answer = -1;
    for (int i = 0; i < M; i++)
    {
        cin >> t >> r;

        water += r;
        if (water > K && answer == -1)
        {
            answer = i + 1;
        }
    }

    if (answer != -1)
    {
        cout << answer << " 1\n";
    }
    else
    {
        cout << "-1\n";
    }

    return 0;
}