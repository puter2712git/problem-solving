#include <iostream>
#include <vector>

using namespace std;

int GetBingoCount(vector<vector<bool>> &board)
{
    int count = 0;

    // 가로 체크
    for (int i = 0; i < 5; i++)
    {
        if (board[i][0] && board[i][1] && board[i][2] && board[i][3] && board[i][4])
        {
            count++;
        }
    }

    // 세로 체크
    for (int i = 0; i < 5; i++)
    {
        if (board[0][i] && board[1][i] && board[2][i] && board[3][i] && board[4][i])
        {
            count++;
        }
    }

    // 대각선 체크
    if (board[0][0] && board[1][1] && board[2][2] && board[3][3] && board[4][4])
    {
        count++;
    }
    if (board[0][4] && board[1][3] && board[2][2] && board[3][1] && board[4][0])
    {
        count++;
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<bool>> board = vector<vector<bool>>(5, vector<bool>(5, false));
    vector<pair<int, int>> indices = vector<pair<int, int>>(26, {0, 0});
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int tmp;
            cin >> tmp;
            indices[tmp] = {i, j};
        }
    }

    int bingoIndex = -1;

    for (int i = 0; i < 25; i++)
    {
        int num;
        cin >> num;

        int y = indices[num].first;
        int x = indices[num].second;

        board[y][x] = true;

        if (bingoIndex == -1 && GetBingoCount(board) >= 3)
        {
            bingoIndex = i + 1;
        }
    }

    cout << bingoIndex << "\n";

    return 0;
}