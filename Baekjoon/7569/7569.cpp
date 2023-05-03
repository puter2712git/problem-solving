#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int box[100][100][100];
int m, n, h;

bool is_visited[100][100][100];
int day[100][100][100];

int last_day = 0;

tuple<int, int, int> diff[6] = {
    {  0,  0,  1 },
    {  0,  0, -1 },
    { -1,  0,  0 },
    {  1,  0,  0 },
    {  0,  1,  0 },
    {  0, -1,  0 },
};

void bfs()
{
    queue<tuple<int, int, int>> q;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (box[i][j][k] == 1) {
                    q.push(make_tuple(k, j, i));

                    is_visited[i][j][k] = true;
                }
            }
        }
    }

    while (!q.empty()) {
        tuple<int, int, int> point = q.front();
        q.pop();

        int x = get<0>(point);
        int y = get<1>(point);
        int z = get<2>(point);

        for (int i = 0; i < 6; i++) {
            int nx = get<0>(point);
            int ny = get<1>(point);
            int nz = get<2>(point);

            nx += get<0>(diff[i]);
            ny += get<1>(diff[i]);
            nz += get<2>(diff[i]);

            if (nx < 0 || nx >= m) continue;
            if (ny < 0 || ny >= n) continue;
            if (nz < 0 || nz >= h) continue;

            if (box[nz][ny][nx] == -1) continue;
            if (is_visited[nz][ny][nx]) continue;

            box[nz][ny][nx] = 1;

            is_visited[nz][ny][nx] = true;
            day[nz][ny][nx] = day[z][y][x] + 1;

            last_day = day[nz][ny][nx];

            q.push(make_tuple(nx, ny, nz));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> box[i][j][k];

                is_visited[i][j][k] = false;
                day[i][j][k] = 0;
            }
        }
    }

    bfs();

    int zero_count = 0;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (box[i][j][k] == 0) {
                    zero_count++;
                }
            }
        }

    }

    if (zero_count == 0) {
        cout << last_day << "\n";
    }
    else {
        cout << -1 << "\n";
    }

    return 0;
}