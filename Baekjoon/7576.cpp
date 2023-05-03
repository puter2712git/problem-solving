#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int box[1000][1000];
int m, n;

bool is_visited[1000][1000];
int day[1000][1000];

int last_day;

tuple<int, int> diff[4] = {
    { -1,  0 },
    {  1,  0 },
    {  0,  1 },
    {  0, -1 },
};

void bfs()
{
    queue<tuple<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (box[i][j] == 1) {
                q.push(make_tuple(j, i));

                is_visited[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        tuple<int, int> point = q.front();
        q.pop();

        int x = get<0>(point);
        int y = get<1>(point);

        for (int i = 0; i < 4; i++) {
            int nx = x + get<0>(diff[i]);
            int ny = y + get<1>(diff[i]);

            if (nx < 0 || nx >= m) continue;
            if (ny < 0 || ny >= n) continue;

            if (is_visited[ny][nx]) continue;
            if (box[ny][nx] == -1) continue;

            box[ny][nx] = 1;

            is_visited[ny][nx] = true;
            day[ny][nx] = day[y][x] + 1;

            last_day = day[ny][nx];

            q.push(make_tuple(nx, ny));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> box[i][j];

            is_visited[i][j] = false;
            day[i][j] = 0;
        }
    }

    bfs();

    int zero_count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (box[i][j] == 0) {
                zero_count++;
            }
        }
    }

    if (zero_count == 0) {
        cout << last_day << "\n";
    } else {
        cout << "-1\n";
    }

    return 0;
}