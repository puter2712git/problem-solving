#include <iostream>

using namespace std;

int N;
string S;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> S;

    cout << S[S.length() - 1] << "\n";

    return 0;
}