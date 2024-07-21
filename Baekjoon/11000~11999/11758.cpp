#include <iostream>

using namespace std;

struct Point
{
	int x;
	int y;
};

Point p1, p2, p3;

int GetCCW(Point &p1, Point &p2, Point &p3) { return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y); }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> p1.x >> p1.y;
	cin >> p2.x >> p2.y;
	cin >> p3.x >> p3.y;

	int ccw = GetCCW(p1, p2, p3);

	if (ccw == 0) {
		cout << 0 << "\n";
	} else if (ccw > 0) {
		cout << 1 << "\n";
	} else {
		cout << -1 << "\n";
	}

	return 0;
}