#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Line
{
	int direction;
	int length;
};

int K;
vector<Line> lines;

int GetTotalRectArea()
{
	int ret;

	for (int i = 3; i < 12; i++) {
		if (lines[i].direction == lines[i - 2].direction && lines[i - 1].direction == lines[i - 3].direction) {
			ret = lines[i + 1].length * lines[i + 2].length;
			break;
		}
	}

	return ret;
}

int GetSubRectArea()
{
	int ret;

	for (int i = 3; i < 12; i++) {
		if (lines[i].direction == lines[i - 2].direction && lines[i - 1].direction == lines[i - 3].direction) {
			ret = lines[i - 1].length * lines[i - 2].length;
			break;
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> K;
	lines = vector<Line>(12);
	for (int i = 0; i < 6; i++) {
		int direction, length;
		cin >> direction >> length;

		lines[i] = { direction, length };
		lines[i + 6] = lines[i];
	}

	cout << (GetTotalRectArea() - GetSubRectArea()) * K << "\n";

	return 0;
}