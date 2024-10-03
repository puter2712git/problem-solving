#include <iostream>

using namespace std;

string S;
int T;
int A, B;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> S;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> A >> B;
        swap(S[A], S[B]);
    }

    cout << S << "\n";

    return 0;
}