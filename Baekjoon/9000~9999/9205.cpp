#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point
{
	int x;
	int y;
};

int t;
int n;
Point home;
vector<Point> stores;
Point festival;

vector<bool> visitFlags;

bool IsArrivable()
{
	queue<Point> q;
	q.push(home);

	while (!q.empty()) {
		Point &point = q.front();
		q.pop();

		if (abs(festival.x - point.x) + abs(festival.y - point.y) <= 1000)
			return true;

		for (int i = 0; i < n; i++) {
			if (visitFlags[i])
				continue;

			if (abs(stores[i].x - point.x) + abs(stores[i].y - point.y) <= 1000) {
				visitFlags[i] = true;
				q.push(stores[i]);
			}
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;

	while (t--) {
		cin >> n;
		stores = vector<Point>(n);

		cin >> home.x >> home.y;
		for (int i = 0; i < n; i++) {
			cin >> stores[i].x >> stores[i].y;
		}
		cin >> festival.x >> festival.y;

		visitFlags = vector<bool>(n, false);

		if (IsArrivable()) {
			cout << "happy\n";
		} else {
			cout << "sad\n";
		}
	}

	return 0;
}