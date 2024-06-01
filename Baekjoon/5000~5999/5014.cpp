#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Floor
{
	int visitOrder;
	bool isVisited;
};

int F, S, G, U, D;
vector<Floor> floors;

int GetPressCount()
{
	queue<int> q;
	q.push(S);
	floors[S] = { 0, true };

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		// Up
		int upFloor = curr + U;
		if (upFloor <= F && !floors[upFloor].isVisited) {
			floors[upFloor] = { floors[curr].visitOrder + 1, true };
			q.push(upFloor);
		}

		// Down
		int downFloor = curr - D;
		if (downFloor >= 1 && !floors[downFloor].isVisited) {
			floors[downFloor] = { floors[curr].visitOrder + 1, true };
			q.push(downFloor);
		}
	}

	return floors[G].visitOrder;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> F >> S >> G >> U >> D;
	floors = vector<Floor>(F + 1, Floor{ -1, false });

	int pressCount = GetPressCount();
	if (pressCount == -1) {
		cout << "use the stairs\n";
	} else {
		cout << pressCount << "\n";
	}

	return 0;
}