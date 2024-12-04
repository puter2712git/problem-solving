#include <deque>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

enum Direction
{
    UP,
    RIGHT,
    DOWN,
    LEFT,
};

enum TileType
{
    NONE,
    APPLE,
    SNAKE
};

int N;
int K;
int L;
vector<vector<TileType>> board;
map<int, char> rotationMap;

void Setup()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Input()
{
    cin >> N;
    cin >> K;

    board = vector<vector<TileType>>(N + 1, vector<TileType>(N + 1, TileType::NONE));

    for (int i = 0; i < K; i++)
    {
        int r, c;
        cin >> r >> c;

        board[r][c] = TileType::APPLE;
    }

    cin >> L;

    for (int i = 0; i < L; i++)
    {
        int X;
        char C;
        cin >> X >> C;

        rotationMap[X] = C;
    }
}

void Solve()
{
    int time = 0;
    deque<pair<int, int>> snake;
    Direction dir = Direction::RIGHT;

    board[1][1] = TileType::SNAKE;
    snake.push_front({1, 1});

    while (true)
    {
        time++;

        pair<int, int> currPos = snake.front();
        int r = currPos.first;
        int c = currPos.second;

        int nr = r;
        int nc = c;

        // Move
        switch (dir)
        {
        case Direction::UP:
            nr--;
            break;
        case Direction::RIGHT:
            nc++;
            break;
        case Direction::DOWN:
            nr++;
            break;
        case Direction::LEFT:
            nc--;
            break;
        }

        if (nr < 1 || nr > N || nc < 1 || nc > N)
            break;
        if (board[nr][nc] == TileType::SNAKE)
            break;

        snake.push_front({nr, nc});

        if (board[nr][nc] == TileType::NONE)
        {
            board[snake.back().first][snake.back().second] = TileType::NONE;
            snake.pop_back();
        }

        board[nr][nc] = TileType::SNAKE;

        // Rotate
        if (rotationMap.find(time) != rotationMap.end())
        {
            char rotation = rotationMap[time];

            if (rotation == 'L')
            {
                int dirNum = (int)dir - 1;
                if (dirNum < 0)
                {
                    dirNum += 4;
                }
                dir = static_cast<Direction>(dirNum);
            }
            else if (rotation == 'D')
            {
                int dirNum = (int)dir + 1;
                dirNum %= 4;
                dir = static_cast<Direction>(dirNum);
            }
        }
    }

    cout << time << "\n";
}

int main()
{
    Setup();
    Input();
    Solve();

    return 0;
}