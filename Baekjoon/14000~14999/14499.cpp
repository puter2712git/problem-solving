#include <iostream>
#include <vector>

using namespace std;

struct Vec2
{
    int x;
    int y;
};

enum class Direction
{
    EAST = 1,
    WEST,
    NORTH,
    SOUTH,
};

class Dice
{
public:
    Dice();
    ~Dice() {}

    void Rotate(Direction dir);

    int GetUp() { return up; }
    int GetDown() { return down; }
    void SetDown(int down) { this->down = down; }

private:
    int up;
    int down;
    int front;
    int back;
    int left;
    int right;
};

Dice::Dice()
{
    up = 0;
    down = 0;
    front = 0;
    back = 0;
    left = 0;
    right = 0;
}

void Dice::Rotate(Direction dir)
{
    int tmp;

    switch (dir)
    {
    case Direction::EAST:
        tmp = up;
        up = left;
        left = down;
        down = right;
        right = tmp;
        break;

    case Direction::WEST:
        tmp = up;
        up = right;
        right = down;
        down = left;
        left = tmp;
        break;

    case Direction::NORTH:
        tmp = up;
        up = front;
        front = down;
        down = back;
        back = tmp;
        break;

    case Direction::SOUTH:
        tmp = up;
        up = back;
        back = down;
        down = front;
        front = tmp;
        break;
    }
}

int N, M;
int x, y;
int K;

vector<vector<int>> board;
vector<Direction> operations;

void Process()
{
    Dice dice;

    Vec2 currPos;
    currPos.x = y;
    currPos.y = x;

    for (Direction dir : operations)
    {
        int nx = currPos.x;
        int ny = currPos.y;

        switch (dir)
        {
        case Direction::EAST:
            nx++;
            break;
        case Direction::WEST:
            nx--;
            break;
        case Direction::NORTH:
            ny--;
            break;
        case Direction::SOUTH:
            ny++;
            break;
        }

        if (nx < 0 || nx >= M || ny < 0 || ny >= N)
            continue;

        currPos.x = nx;
        currPos.y = ny;

        dice.Rotate(dir);
        if (board[currPos.y][currPos.x] == 0)
        {
            board[currPos.y][currPos.x] = dice.GetDown();
        }
        else
        {
            dice.SetDown(board[currPos.y][currPos.x]);
            board[currPos.y][currPos.x] = 0;
        }

        cout << dice.GetUp() << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> x >> y >> K;

    board = vector<vector<int>>(N, vector<int>(M));
    operations = vector<Direction>(K);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < K; i++)
    {
        int operation;
        cin >> operation;
        operations[i] = static_cast<Direction>(operation);
    }

    Process();

    return 0;
}