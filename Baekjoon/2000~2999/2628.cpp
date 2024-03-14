#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int row, column;
    int cutCount;

    vector<int> rowCuts, columnCuts;

    cin >> row >> column;
    cin >> cutCount;

    for (int i = 0; i < cutCount; i++) {
        int type, cut;
        cin >> type >> cut;

        switch (type) {
        case 0:
            columnCuts.push_back(cut);
            break;

        case 1:
            rowCuts.push_back(cut);
            break;
        }
    }

    sort(rowCuts.begin(), rowCuts.end());
    sort(columnCuts.begin(), columnCuts.end());

    int maxArea = 0;

    for (int r = 0; r < rowCuts.size() + 1; r++) {
        for (int c = 0; c < columnCuts.size() + 1; c++) {
            int startRow = r == 0 ? 0 : rowCuts[r - 1];
            int endRow = r == rowCuts.size() ? row : rowCuts[r];

            int startColumn = c == 0 ? 0 : columnCuts[c - 1];
            int endColumn = c == columnCuts.size() ? column : columnCuts[c];

            int area = (endRow - startRow) * (endColumn - startColumn);

            if (maxArea < area) {
                maxArea = area;
            }
        }
    }

    cout << maxArea << "\n";

    return 0;
}