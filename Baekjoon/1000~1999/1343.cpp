#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string board;
    cin >> board;

    int count = 0;

    for (int i = 0; i < board.length(); i++) {
        if (board[i] == 'X') {
            count++;

            if (count == 4) {
                board.replace(i - 4 + 1, 4, "AAAA");
                count = 0;
            }
        } else if (board[i] == '.') {
            if (count == 2) {
                board.replace(i - 2, 2, "BB");
                count = 0;
            } else if (count != 0) {
                cout << -1 << "\n";
                return 0;
            }
        }
    }
    if (count == 2) {
        board.replace(board.length() - 2, 2, "BB");
    } else if (count != 0) {
        cout << -1 << "\n";
        return 0;
    }

    cout << board << "\n";
    return 0;
}