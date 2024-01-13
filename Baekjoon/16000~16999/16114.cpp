#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int X, N;
    cin >> X >> N;

    int dec = N / 2;

    // ERROR 처리
    if (N > 1 && N % 2 == 1) {
        cout << "ERROR" << "\n";
    }
    // 0 처리
    else if (X == 0 || (X < 0 && N != 1) || (X > 0 && N == 1))
    {
        cout << "0" << "\n";
    }
    // INFINITE 처리
    else if (N == 0 || (X < 0 && N == 1)) {
        cout << "INFINITE" << "\n";
    }
    // 그 외
    else {
        if (X % dec == 0) {
            cout << X / dec - 1 << "\n";
        }
        else {
            cout << X / dec << "\n";
        }
    }

    return 0;
}