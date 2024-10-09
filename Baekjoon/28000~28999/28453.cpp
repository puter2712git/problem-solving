#include <iostream>

using namespace std;

int N;
int M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> M;

        if (M == 300)
        {
            cout << "1 ";
        }
        else if (M >= 275 && M < 300)
        {
            cout << "2 ";
        }
        else if (M >= 250 && M < 275)
        {
            cout << "3 ";
        }
        else
        {
            cout << "4 ";
        }
    }
    cout << "\n";

    return 0;
}