#include <iostream>
#include <vector>

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    vector<int> A;

    A.push_back(N);
    for (int i = 1; i <= N - 1; i++)
    {
        A.push_back(i);
    }

    for (int i = 0; i < N; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\n";

    return 0;
}