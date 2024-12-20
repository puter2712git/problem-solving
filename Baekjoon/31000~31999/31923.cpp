#include <iostream>
#include <vector>

using namespace std;

int N, P, Q;
vector<int> A, B;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> P >> Q;

    A = vector<int>(N);
    B = vector<int>(N);

    for (int &a : A)
    {
        cin >> a;
    }
    for (int &b : B)
    {
        cin >> b;
    }

    vector<int> answers;

    for (int i = 0, cnt = 0; i < N; i++)
    {
        cnt = 0;
        int &a = A[i];
        int &b = B[i];

        while (a != b)
        {
            a += P;
            b += Q;
            cnt++;

            if (cnt == 10000)
            {
                cout << "NO\n";
                return 0;
            }
        }

        answers.push_back(cnt);
    }

    cout << "YES\n";

    for (int ans : answers)
    {
        cout << ans << " ";
    }
    cout << "\n";

    return 0;
}