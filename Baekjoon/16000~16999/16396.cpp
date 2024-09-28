#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> line(10'001, 0);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;

        for (int j = x; j < y; j++)
        {
            line[j] = 1;
        }
    }

    int lineSum = 0;
    for (int i = 1; i <= 10'000; i++)
    {
        if (line[i] == 1)
        {
            lineSum++;
        }
    }

    cout << lineSum << "\n";

    return 0;
}