#include <iostream>

using namespace std;

int num1, num2;
int a, b, c, d, q, r;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> num1 >> num2;

	a = 100 - num1;
	b = 100 - num2;
	c = 100 - (a + b);
	d = a * b;
	q = d / 100;
	r = d % 100;

	cout << a << " " << b << " " << c << " " << d << " " << q << " " << r << "\n";
	cout << c + q << " " << r << "\n";

	return 0;
}