#include <iostream>
#include <vector>

using namespace std;

struct Point
{
	int x;
	int y;
};

int N;
vector<Point> points;

int Q;
double k;

int GetFunctionType(double x)
{
	int beginIndex = 0;
	int endIndex = N - 1;
	int mid;

	while (beginIndex < endIndex) {
		mid = (beginIndex + endIndex) / 2;
		if (beginIndex + 1 == endIndex)
			break;

		if (points[mid].x < x)
			beginIndex = mid;
		else
			endIndex = mid;
	}

	int beginY = points[mid].y;
	int endY = points[mid + 1].y;

	int ret;
	if (beginY < endY)
		ret = 1;
	else if (beginY > endY)
		ret = -1;
	else
		ret = 0;

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	points = vector<Point>(N, Point{ 0, 0 });
	for (int i = 0; i < N; i++) {
		cin >> points[i].x >> points[i].y;
	}

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> k;
		cout << GetFunctionType(k) << "\n";
	}

	return 0;
}