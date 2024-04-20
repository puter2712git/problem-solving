/** 백준 1004 어린 왕자
 *
 * 행성계의 진입/이탈 횟수를 구하는 문제이다.
 *
 * 시작 위치를 포함하고 도착 위치를 포함하지 않는 행성계가
 * 행성계의 총 이탈 횟수이다.
 * 역으로, 시작 위치를 포함하지 않고 도착 위치를 포함하는
 * 행성계가 총 진입 횟수이다.
 * 시작 위치와 도착 위치를 전부 포함하거나 전부 포함하지 않는
 * 행성계는 무시해도 된다.
 */

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Point
{
public:
	Point()
	{
	}
	Point(int x, int y)
	{
		_x = x;
		_y = y;
	}
	~Point()
	{
	}

	int GetX()
	{
		return _x;
	}
	int GetY()
	{
		return _y;
	}

private:
	int _x;
	int _y;
};

class Planet
{
public:
	Planet()
	{
	}
	Planet(int x, int y, int r)
	{
		_x = x;
		_y = y;
		_radius = r;
	}
	~Planet()
	{
	}

	int GetX()
	{
		return _x;
	}
	int GetY()
	{
		return _y;
	}
	int GetRadius()
	{
		return _radius;
	}

private:
	int _x;
	int _y;
	int _radius;
};

Point beginPoint;
Point endPoint;
vector<Planet> planets;

bool IsPointInPlanet(Point& p, Planet& planet)
{
	double dist = sqrt(
	    pow(p.GetX() - planet.GetX(), 2) + pow(p.GetY() - planet.GetY(), 2));

	return dist < planet.GetRadius();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int testcaseLen;
	cin >> testcaseLen;

	for (int i = 0; i < testcaseLen; i++)
	{
		int x1, y1;
		int x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		beginPoint = Point(x1, y1);
		endPoint = Point(x2, y2);

		int planetLen;
		cin >> planetLen;

		planets.clear();

		for (int j = 0; j < planetLen; j++)
		{
			int cx, cy, r;
			cin >> cx >> cy >> r;
			planets.push_back(Planet(cx, cy, r));
		}

		int count = 0;
		for (auto planet : planets)
		{
			// 진입 횟수
			if (IsPointInPlanet(endPoint, planet) &&
			    !IsPointInPlanet(beginPoint, planet))
			{
				count++;
			}

			// 이탈 횟수
			if (IsPointInPlanet(beginPoint, planet) &&
			    !IsPointInPlanet(endPoint, planet))
			{
				count++;
			}
		}

		cout << count << "\n";
	}

	return 0;
}