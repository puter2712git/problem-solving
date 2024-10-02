#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> A;
vector<int> B;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    A = vector<int>(N);
    B = vector<int>(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }

    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] <= B[i])
        {
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}