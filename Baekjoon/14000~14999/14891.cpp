#include <cmath>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class Gear
{
public:
	Gear() {}
	Gear(string &pStates)
	{
		for (const auto &p : pStates) {
			poles.push_back(p);
		}
	};

	deque<char> poles;
	int currDir;

	void Rotate(int direction)
	{
		currDir = direction;

		if (currDir == 1) {
			int p = poles.back();
			poles.pop_back();
			poles.push_front(p);
		} else if (currDir == -1) {
			int p = poles.front();
			poles.pop_front();
			poles.push_back(p);
		}
	}
};

vector<Gear> gears;
int K;

void RotateGear(int index, int dir)
{
	vector<int> rotateDirs = vector<int>(4 + 1, 0);

	auto targetGear = gears[index];
	rotateDirs[index] = dir;

	for (int i = index - 1; i >= 1; i--) {
		if (rotateDirs[i + 1] == 0)
			continue;

		if (gears[i + 1].poles[6] != gears[i].poles[2]) {
			rotateDirs[i] = rotateDirs[i + 1] == 1 ? -1 : 1;
		}
	}

	for (int i = index + 1; i <= 4; i++) {
		if (rotateDirs[i - 1] == 0)
			continue;

		if (gears[i - 1].poles[2] != gears[i].poles[6]) {
			rotateDirs[i] = rotateDirs[i - 1] == 1 ? -1 : 1;
		}
	}

	for (int i = 1; i <= 4; i++) {
		if (rotateDirs[i] == 0)
			continue;

		gears[i].Rotate(rotateDirs[i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	gears = vector<Gear>(4 + 1);
	for (int i = 1; i <= 4; i++) {
		string poleStates;
		cin >> poleStates;
		gears[i] = Gear(poleStates);
	}

	cin >> K;
	while (K--) {
		int index, dir;
		cin >> index >> dir;
		RotateGear(index, dir);
	}

	int point = 0;
	for (int i = 1; i <= 4; i++) {
		if (gears[i].poles[0] == '1') {
			point += pow(2, i - 1);
		}
	}

	cout << point << "\n";

	return 0;
}