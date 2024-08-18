#include <iostream>

using namespace std;

int A, B;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> A >> B;

	if (B >= A - 1) {
		cout << 2 * A - 1 << "\n";
	} else {
		cout << 2 * (B + 1) - 1 << "\n";
	}

	return 0;
}