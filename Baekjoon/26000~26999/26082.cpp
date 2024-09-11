#include <iostream>

using namespace std;

int A, B, C;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> A >> B >> C;

	int quality = B / A * C * 3;
	cout << quality << "\n";

	return 0;
}