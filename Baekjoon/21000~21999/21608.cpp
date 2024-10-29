#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Seat
{
    int studentId = -1;
};

struct SeatData
{
    int r;
    int c;
    int likeCount;
    int emptyCount;

    bool operator<(const SeatData &data)
    {
        if (likeCount != data.likeCount)
        {
            return likeCount > data.likeCount;
        }
        if (emptyCount != data.emptyCount)
        {
            return emptyCount > data.emptyCount;
        }
        if (r != data.r)
        {
            return r < data.r;
        }
        return c < data.c;
    }
};

struct StudentData
{
    int id;
    int likes[4];
};

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int N;
vector<vector<Seat>> seats;
vector<StudentData> students;
vector<vector<bool>> isVisited;

SeatData GetSeatData(const StudentData &student, int r, int c)
{
    SeatData ret = {r, c, 0, 0};

    for (int i = 0; i < 4; i++)
    {
        int row = r + dx[i];
        int column = c + dy[i];
        if (row <= 0 || row > N || column <= 0 || column > N)
            continue;

        if (seats[row][column].studentId == -1)
        {
            ret.emptyCount++;
        }
        else
        {
            for (const int &likeId : student.likes)
            {
                if (likeId == seats[row][column].studentId)
                {
                    ret.likeCount++;
                    break;
                }
            }
        }
    }

    return ret;
}

void Dfs(const StudentData &student)
{
    queue<pair<int, int>> q;
    q.push({1, 1});
    isVisited[1][1] = true;

    vector<SeatData> seatDatas;

    while (!q.empty())
    {
        pair<int, int> popped = q.front();
        q.pop();

        if (seats[popped.first][popped.second].studentId == -1)
        {
            seatDatas.push_back(GetSeatData(student, popped.first, popped.second));
        }

        for (int i = 0; i < 4; i++)
        {
            int r = popped.first + dx[i];
            int c = popped.second + dy[i];
            if (r <= 0 || r > N || c <= 0 || c > N)
                continue;
            if (isVisited[r][c])
                continue;

            q.push({r, c});
            isVisited[r][c] = true;
        }
    }

    sort(seatDatas.begin(), seatDatas.end());

    SeatData data = seatDatas[0];
    seats[data.r][data.c].studentId = student.id;
}

int GetSatisfaction(int r, int c)
{
    StudentData student;
    for (const StudentData &s : students)
    {
        if (s.id == seats[r][c].studentId)
        {
            student = s;
            break;
        }
    }

    int likeCount = 0;
    for (int i = 0; i < 4; i++)
    {
        int row = r + dx[i];
        int column = c + dy[i];
        if (row <= 0 || row > N || column <= 0 || column > N)
            continue;

        for (const int &likeId : student.likes)
        {
            if (seats[row][column].studentId == likeId)
            {
                likeCount++;
                break;
            }
        }
    }

    return likeCount > 0 ? pow(10, likeCount - 1) : 0;
}

int GetSatisfactionTotal()
{
    int ret = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            ret += GetSatisfaction(i, j);
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    seats = vector<vector<Seat>>(N + 1, vector<Seat>(N + 1, {-1}));
    students = vector<StudentData>(N * N, {-1, {0}});

    for (int i = 0; i < N * N; i++)
    {
        cin >> students[i].id;
        for (int j = 0; j < 4; j++)
        {
            cin >> students[i].likes[j];
        }
    }

    for (const StudentData &student : students)
    {
        isVisited = vector<vector<bool>>(N + 1, vector<bool>(N + 1, false));
        Dfs(student);
    }

    cout << GetSatisfactionTotal() << "\n";

    return 0;
}