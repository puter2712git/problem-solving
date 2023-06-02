#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    int a;
    int b;

    vector<int> A;
    vector<int> B;

    int sum = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> a;
        A.push_back(a);
    }

    for (int i = 0; i < N; i++)
    {
        cin >> b;
        B.push_back(b);
    }

    sort(A.begin(), A.end(), compare);
    sort(B.begin(), B.end());

    for (int i = 0; i < N; i++)
    {
        sum += A[i] * B[i];
    }

    cout << sum << "\n";

    return 0;
}