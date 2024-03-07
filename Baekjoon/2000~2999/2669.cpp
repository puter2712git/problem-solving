#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<bool>> coloredList = vector<vector<bool>>(101, vector<bool>(101, false));

    for (int i = 0; i < 4; i++) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;

        for (int x = lx; x < rx; x++) {
            for (int y = ly; y < ry; y++) {
                coloredList[x][y] = true;
            }
        }
    }

    int area = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            area += coloredList[i][j] ? 1 : 0;
        }
    }

    cout << area << "\n";

    return 0;
}