#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int row, column;
    vector<vector<int>> matrix;

    cin >> row >> column;
    for (int i = 0; i < row; i++) {
        matrix.push_back(vector<int>());
        for (int j = 0; j < column; j++) {
            int tmp;
            cin >> tmp;
            matrix[i].push_back(tmp);
        }
    }

    int sumCount;
    cin >> sumCount;

    for (int i = 0; i < sumCount; i++) {
        int baseRow, baseColumn, targetRow, targetColumn;
        int sum = 0;

        cin >> baseRow >> baseColumn >> targetRow >> targetColumn;

        for (int r = baseRow - 1; r < targetRow; r++) {
            for (int c = baseColumn - 1; c < targetColumn; c++) {
                sum += matrix[r][c];
            }
        }

        cout << sum << "\n";
    }

    return 0;
}