#include <iostream>
#include <string>
#include <vector>

using namespace std;

int get_row_count(vector<string> &room)
{
    int ret = 0;
    bool flag = false;
    bool is_flagged = false;

    for (int i = 0; i < room.size(); i++) {
        flag = false;
        is_flagged = false;

        for (int j = 0; j < room.size(); j++) {
            if (room[i][j] == 'X') {
                flag = false;
                is_flagged = false;
            }
            else if (flag && !is_flagged) {
                ret++;
                is_flagged = true;
            }
            else {
                flag = true;
            }
        }
    }

    return ret;
}

int get_col_count(vector<string> &room)
{
    int ret = 0;
    bool flag = false;
    bool is_flagged = false;

    for (int i = 0; i < room.size(); i++) {
        flag = false;
        is_flagged = false;

        for (int j = 0; j < room.size(); j++) {
            if (room[j][i] == 'X') {
                flag = false;
                is_flagged = false;
            }
            else if (flag && !is_flagged) {
                ret++;
                is_flagged = true;
            }
            else {
                flag = true;
            }
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int room_size;
    vector<string> room;

    cin >> room_size;
    for (int i = 0; i < room_size; i++) {
        string r;
        cin >> r;
        room.push_back(r);
    }

    cout << get_row_count(room) << " " << get_col_count(room) << "\n";

    return 0;
}