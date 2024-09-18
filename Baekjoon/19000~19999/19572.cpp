#include <iostream>

using namespace std;

int d1, d2, d3;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout.precision(1);
	cout << fixed;

	cin >> d1 >> d2 >> d3;

	double a = (d1 + d2 - d3) / 2.0;
	double b = d1 - a;
	double c = d2 - a;

	if (a > 0 && b > 0 && c > 0) {
		cout << "1\n";
		cout << a << " " << b << " " << c << "\n";
	} else {
		cout << "-1\n";
	}

	return 0;
}