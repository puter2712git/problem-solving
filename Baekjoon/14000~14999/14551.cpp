#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> A;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    A = vector<int>(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    int count = 1;
    for (int i = 0; i < N; i++)
    {
        if (A[i] == 0)
        {
            A[i] = 1;
        }

        count *= A[i];
        count %= M;
    }

    cout << count % M << "\n";

    return 0;
}