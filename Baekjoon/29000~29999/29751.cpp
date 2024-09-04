#include <iostream>

using namespace std;

int W, H;
double area;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cout << fixed;
	cout.precision(1);

	cin >> W >> H;

	area = W * H * 0.5;
	cout << area << "\n";

	return 0;
}