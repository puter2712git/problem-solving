#include <iostream>

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true)
    {
        cin >> N;
        if (N == 0)
        {
            break;
        }

        int tmp;
        int before = -1;
        for (int i = 0; i < N; i++)
        {
            cin >> tmp;
            if (before == tmp)
            {
                continue;
            }

            before = tmp;
            cout << tmp << " ";
        }

        cout << "$\n";
    }

    return 0;
}