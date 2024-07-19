#include <iostream>
#include <vector>

using namespace std;

struct Point
{
	long long x;
	long long y;
};

int N;
vector<Point> points;

double GetCCW(Point &p1, Point &p2, Point &p3)
{
	double ret = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	ret += (-p1.y * p2.x - p2.y * p3.x - p3.y * p1.x);
	return ret / 2;
}

double GetArea()
{
	double ret = 0.0f;

	for (int i = 1; i < N; i++) {
		ret += GetCCW(points[0], points[i - 1], points[i]);
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed;
	cout.precision(1);

	cin >> N;
	points = vector<Point>(N);

	for (int i = 0; i < N; i++) {
		cin >> points[i].x >> points[i].y;
	}

	double area = abs(GetArea());
	cout << area << "\n";

	return 0;
}