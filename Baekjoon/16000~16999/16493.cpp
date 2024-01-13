#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    int N, M;
    int day, page;
    vector<pair<int, int>> chapters;

    cin >> N >> M;
    vector<vector<int>> max_page(M + 1, vector<int>(201, 0));

    chapters.push_back({ 0, 0 });
    for (int i = 0; i < M; i++) {
        cin >> day >> page;
        chapters.push_back({ day, page });
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (j < chapters[i].first) {
                max_page[i][j] = max_page[i - 1][j];
            }
            else {
                max_page[i][j] = max(max_page[i - 1][j], max_page[i - 1][j - chapters[i].first] + chapters[i].second);
            }
        }
    }

    int max_value = 0;

    for (int i = 1; i <= M; i++) {
        if (max_value < max_page[i][N]) {
            max_value = max_page[i][N];
        }
    }

    cout << max_value << "\n";

    return 0;
}