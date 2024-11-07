#include <iostream>
#include <vector>

using namespace std;

enum Direction
{
    LEFT = 1,
    TOP_LEFT,
    TOP,
    TOP_RIGHT,
    RIGHT,
    BOTTOM_RIGHT,
    BOTTOM,
    BOTTOM_LEFT,
};

struct Position
{
    int row;
    int column;
};

struct Operation
{
    Direction direction;
    int moveCount;
};

struct Tile
{
    int water;
    bool isClouded;
};

int N, M;
vector<vector<Tile>> grid;
vector<Operation> operations;

void Setup()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Input()
{
    cin >> N >> M;
    grid = vector<vector<Tile>>(N + 1, vector<Tile>(N + 1, {0, false}));
    operations = vector<Operation>(M);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> grid[i][j].water;
        }
    }

    int dir;
    for (int i = 0; i < M; i++)
    {
        cin >> dir >> operations[i].moveCount;
        operations[i].direction = static_cast<Direction>(dir);
    }
}

void ClampPosition(Position &pos)
{
    while (pos.row < 1)
    {
        pos.row += N;
    }
    while (pos.row > N)
    {
        pos.row -= N;
    }

    while (pos.column < 1)
    {
        pos.column += N;
    }
    while (pos.column > N)
    {
        pos.column -= N;
    }
}

void PerformOperation(vector<Position> &cloudPositions, Operation &operation)
{
    switch (operation.direction)
    {
    case Direction::LEFT:
        for (Position &pos : cloudPositions)
        {
            pos.column -= operation.moveCount;
            ClampPosition(pos);
        }
        break;

    case Direction::TOP_LEFT:
        for (Position &pos : cloudPositions)
        {
            pos.row -= operation.moveCount;
            pos.column -= operation.moveCount;
            ClampPosition(pos);
        }
        break;

    case Direction::TOP:
        for (Position &pos : cloudPositions)
        {
            pos.row -= operation.moveCount;
            ClampPosition(pos);
        }
        break;

    case Direction::TOP_RIGHT:
        for (Position &pos : cloudPositions)
        {
            pos.row -= operation.moveCount;
            pos.column += operation.moveCount;
            ClampPosition(pos);
        }
        break;

    case Direction::RIGHT:
        for (Position &pos : cloudPositions)
        {
            pos.column += operation.moveCount;
            ClampPosition(pos);
        }
        break;

    case Direction::BOTTOM_RIGHT:
        for (Position &pos : cloudPositions)
        {
            pos.row += operation.moveCount;
            pos.column += operation.moveCount;
            ClampPosition(pos);
        }
        break;

    case Direction::BOTTOM:
        for (Position &pos : cloudPositions)
        {
            pos.row += operation.moveCount;
            ClampPosition(pos);
        }
        break;

    case Direction::BOTTOM_LEFT:
        for (Position &pos : cloudPositions)
        {
            pos.row += operation.moveCount;
            pos.column -= operation.moveCount;
            ClampPosition(pos);
        }
        break;
    }
}

void Rain(vector<Position> &cloudPositions)
{
    for (Position &pos : cloudPositions)
    {
        grid[pos.row][pos.column].water++;
    }
}

const Position DIAGONAL_MOVES[4] = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
int GetDiagonalWaterCount(Position &pos)
{
    int ret = 0;
    int row, column;

    for (const Position &move : DIAGONAL_MOVES)
    {
        row = pos.row + move.row;
        column = pos.column + move.column;

        if (row < 1 || row > N || column < 1 || column > N)
            continue;

        if (grid[row][column].water > 0)
        {
            ret++;
        }
    }

    return ret;
}

void UpdateCloudPositions(vector<Position> &cloudPositions)
{
    cloudPositions.clear();

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (grid[i][j].isClouded)
            {
                grid[i][j].isClouded = false;
                continue;
            }

            if (grid[i][j].water >= 2)
            {
                cloudPositions.push_back({i, j});
                grid[i][j].water -= 2;
            }
        }
    }
}

void Solve()
{
    vector<Position> cloudPositions = {{N, 1}, {N, 2}, {N - 1, 1}, {N - 1, 2}};

    for (auto &operation : operations)
    {
        PerformOperation(cloudPositions, operation);
        Rain(cloudPositions);

        for (Position &position : cloudPositions)
        {
            int diagonalCount = GetDiagonalWaterCount(position);
            grid[position.row][position.column].water += diagonalCount;
            grid[position.row][position.column].isClouded = true;
        }

        UpdateCloudPositions(cloudPositions);
    }

    int totalWater = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            totalWater += grid[i][j].water;
        }
    }

    cout << totalWater << "\n";
}

int main()
{
    Setup();
    Input();
    Solve();

    return 0;
}