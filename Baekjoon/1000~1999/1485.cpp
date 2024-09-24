#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point
{
    int x;
    int y;
};

int T;

double GetDistance(Point &p1, Point &p2)
{
    double ret = sqrtl(powl(p1.x - p2.x, 2) + powl(p1.y - p2.y, 2));
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;

    while (T--)
    {
        vector<Point> points(4, Point{0, 0});

        for (int i = 0; i < 4; i++)
        {
            cin >> points[i].x >> points[i].y;
        }

        vector<double> lengths;
        for (int i = 0; i < 3; i++)
        {
            for (int j = i + 1; j < 4; j++)
            {
                double len = GetDistance(points[i], points[j]);
                lengths.push_back(len);
            }
        }
        sort(lengths.begin(), lengths.end(), less<double>());

        bool isSquare = true;
        for (int i = 0; i < 3; i++)
        {
            if (lengths[i] != lengths[i + 1])
            {
                isSquare = false;
            }
        }

        if (lengths[4] != lengths[5])
        {
            isSquare = false;
        }

        if (isSquare)
        {
            cout << "1\n";
        }
        else
        {
            cout << "0\n";
        }
    }

    return 0;
}