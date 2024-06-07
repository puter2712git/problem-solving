#include <iostream>

using namespace std;

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	if (n % 2 != 0) {
		cout << "Bob" << "\n";
	} else {
		cout << "Alice" << "\n";
		cout << n / 2 << "\n";
	}

	return 0;
}