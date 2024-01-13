#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int pic_size;
char pic[101][101];

bool is_visited[101][101];

int color_area_count_blindness;
int color_area_count_normal;

pair<int, int> diff[4] = {
    { -1,  0 },
    {  1,  0 },
    {  0, -1 },
    {  0,  1 },
};

void bfs()
{
    queue<tuple<int, int, char>> q;
    q.push(make_tuple(0, 0, pic[0][0]));
    is_visited[0][0] = true;

    while (true) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        char color = get<2>(q.front());

        is_visited[y][x] = true;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + diff[i].first;
            int ny = y + diff[i].second;

            if (nx < 0 || nx >= pic_size) continue;
            if (ny < 0 || ny >= pic_size) continue;
            if (pic[ny][nx] != color) continue;
            if (is_visited[ny][nx]) continue;

            is_visited[ny][nx] = true;
            q.push(make_tuple(nx, ny, pic[ny][nx]));
        }

        if (q.empty()) {
            color_area_count_normal++;

            bool is_all_visited = true;

            for (int i = 0; i < pic_size; i++) {
                for (int j = 0; j < pic_size; j++) {
                    if (!is_visited[i][j]) {
                        q.push(make_tuple(j, i, pic[i][j]));
                        is_all_visited = false;
                        break;
                    }
                }
                if (!is_all_visited) break;
            }

            if (is_all_visited) break;
        }
    }
}

void bfs_color_blindness()
{
    queue<tuple<int, int, char>> q;
    q.push(make_tuple(0, 0, pic[0][0]));
    is_visited[0][0] = true;

    while (true) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        char color = get<2>(q.front());

        is_visited[y][x] = true;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + diff[i].first;
            int ny = y + diff[i].second;

            if (nx < 0 || nx >= pic_size) continue;
            if (ny < 0 || ny >= pic_size) continue;
            if (pic[ny][nx] != color) continue;
            if (is_visited[ny][nx]) continue;

            is_visited[ny][nx] = true;
            q.push(make_tuple(nx, ny, pic[ny][nx]));
        }

        if (q.empty()) {
            color_area_count_blindness++;

            bool is_all_visited = true;

            for (int i = 0; i < pic_size; i++) {
                for (int j = 0; j < pic_size; j++) {
                    if (!is_visited[i][j]) {
                        q.push(make_tuple(j, i, pic[i][j]));
                        is_all_visited = false;
                        break;
                    }
                }
                if (!is_all_visited) break;
            }

            if (is_all_visited) break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> pic_size;

    for (int i = 0; i < pic_size; i++) {
        for (int j = 0; j < pic_size; j++) {
            cin >> pic[i][j];
            is_visited[i][j] = false;
        }
    }

    color_area_count_blindness = 0;
    color_area_count_normal = 0;

    bfs();

    for (int i = 0; i < pic_size; i++) {
        for (int j = 0; j < pic_size; j++) {
            if (pic[i][j] == 'G') pic[i][j] = 'R';
            is_visited[i][j] = false;
        }
    }

    bfs_color_blindness();

    cout << color_area_count_normal << " " << color_area_count_blindness << '\n';

    return 0;
}