#include <iostream>

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    int counter = 1;

    for (int i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            counter = N / i;
            break;
        }
    }

    cout << N - counter << "\n";

    return 0;
}