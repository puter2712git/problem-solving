#include <iostream>

using namespace std;

int x, y;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> x >> y;

	if (x > y) {
		cout << x + y << "\n";
	} else {
		cout << y - x << "\n";
	}

	return 0;
}