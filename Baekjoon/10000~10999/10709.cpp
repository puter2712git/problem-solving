#include <iostream>
#include <vector>

using namespace std;

void FillCloud(vector<vector<int>>& record, int w, int h)
{
    int width = record[0].size();
    int curr = 0;

    for (int i = w; i < width; i++) {
        record[h][i] = curr++;
    }
}

void UpdateRecord(vector<vector<char>>& region, vector<vector<int>>& record)
{
    int height = region.size();
    int width = region[0].size();

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (region[i][j] == 'c') {
                FillCloud(record, j, i);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int width, height;
    vector<vector<char>> region;
    vector<vector<int>> record;

    cin >> height >> width;
    for (int i = 0; i < height; i++) {
        region.push_back(vector<char>());
        record.push_back(vector<int>());

        for (int j = 0; j < width; j++) {
            char tmp;
            cin >> tmp;
            region[i].push_back(tmp);
            record[i].push_back(-1);
        }
    }

    UpdateRecord(region, record);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << record[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}