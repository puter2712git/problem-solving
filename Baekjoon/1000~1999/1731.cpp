#include <iostream>

using namespace std;

int N;
int arr[50];

bool IsArithmetic()
{
    int diff = arr[1] - arr[0];
    for (int i = 1; i < N - 1; i++)
    {
        if (arr[i + 1] - arr[i] != diff)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    if (IsArithmetic())
    {
        cout << arr[N - 1] + (arr[1] - arr[0]) << "\n";
    }
    else
    {
        cout << arr[N - 1] * (arr[1] / arr[0]) << "\n";
    }

    return 0;
}