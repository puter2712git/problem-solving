#include <iostream>
#include <vector>

using namespace std;

enum Direction
{
	UP = 0,
	RIGHT = 1,
	DOWN = 2,
	LEFT = 3,
};

struct Tile
{
	int type;
	bool isCleared;
};

class Robot
{
public:
	Robot();
	Robot(int row, int column, Direction dir);
	~Robot();
	int GetRow();
	int GetColumn();
	Direction GetDirection();

	void RotateCounterClockwise();
	pair<int, int> GetFrontIndex();
	pair<int, int> GetBackIndex();
	void Move(int row, int column);

private:
	int mRow;
	int mColumn;
	Direction mDirection;
};

int N, M;
int r, c, d;

Robot robot;
vector<vector<Tile>> room;

int clearCount;

void RunSimulation()
{
	clearCount = 1;
	room[robot.GetRow()][robot.GetColumn()].isCleared = true;

	while (true) {
		int currRow = robot.GetRow();
		int currColumn = robot.GetColumn();

		bool isCleared = false;

		// 반시계 방향으로 회전하며, 청소할 칸이 앞에 있으면 전진
		for (int i = 0; i < 4; i++) {
			robot.RotateCounterClockwise();
			pair<int, int> frontIndex = robot.GetFrontIndex();
			int nextRow = frontIndex.first;
			int nextColumn = frontIndex.second;

			if (nextRow < 0 || nextRow >= N || nextColumn < 0 || nextColumn >= M)
				continue;
			if (room[nextRow][nextColumn].type == 1 || room[nextRow][nextColumn].isCleared)
				continue;

			room[nextRow][nextColumn].isCleared = true;
			clearCount++;

			isCleared = true;
			robot.Move(nextRow, nextColumn);
			break;
		}

		if (isCleared)
			continue;

		pair<int, int> backIndex = robot.GetBackIndex();
		int backRow = backIndex.first;
		int backColumn = backIndex.second;

		if (backRow < 0 || backRow >= N || backColumn < 0 || backColumn >= M)
			break;
		if (room[backRow][backColumn].type == 1)
			break;

		robot.Move(backRow, backColumn);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	cin >> r >> c >> d;

	robot = Robot(r, c, static_cast<Direction>(d));
	room = vector<vector<Tile>>(N, vector<Tile>(M, Tile{ 0, false }));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> room[i][j].type;
		}
	}

	RunSimulation();

	cout << clearCount << "\n";

	return 0;
}

Robot::Robot() {}

Robot::Robot(int row, int column, Direction dir)
{
	mRow = row;
	mColumn = column;
	mDirection = dir;
}

Robot::~Robot() {}

int Robot::GetRow() { return mRow; }
int Robot::GetColumn() { return mColumn; }
Direction Robot::GetDirection() { return mDirection; }

void Robot::RotateCounterClockwise()
{
	int dirIndex = static_cast<int>(mDirection);

	dirIndex--;
	if (dirIndex < 0)
		dirIndex += 4;

	mDirection = static_cast<Direction>(dirIndex);
}

pair<int, int> Robot::GetFrontIndex()
{
	int r = mRow;
	int c = mColumn;

	switch (mDirection) {
	case UP:
		r--;
		break;
	case RIGHT:
		c++;
		break;
	case DOWN:
		r++;
		break;
	case LEFT:
		c--;
		break;
	}

	return { r, c };
}

pair<int, int> Robot::GetBackIndex()
{
	int r = mRow;
	int c = mColumn;

	switch (mDirection) {
	case UP:
		r++;
		break;
	case RIGHT:
		c--;
		break;
	case DOWN:
		r--;
		break;
	case LEFT:
		c++;
		break;
	}

	return { r, c };
}

void Robot::Move(int row, int column)
{
	mRow = row;
	mColumn = column;
}