#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Line
{
    int begin;
    int end;

    bool operator<(const Line &line) const
    {
        if (begin < line.begin)
            return true;
        return false;
    }
};

int N;
vector<Line> lines;

void Input()
{
    cin >> N;
    lines = vector<Line>(N);
    for (int i = 0; i < N; i++)
    {
        cin >> lines[i].begin >> lines[i].end;
    }
}

void Solve()
{
    sort(lines.begin(), lines.end(), less<Line>());

    int answer = 0;
    int left = -1'000'000'999;
    int right = -1'000'000'999;

    for (int i = 0; i < N; i++)
    {
        if (lines[i].begin <= right)
        {
            right = max(right, lines[i].end);
        }
        else
        {
            answer += right - left;
            left = lines[i].begin;
            right = lines[i].end;
        }
    }

    answer += right - left;

    cout << answer << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solve();

    return 0;
}