#include <iostream>

using namespace std;

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (cin >> n) {
		int num = 1;
		int len = 1;

		while (num % n != 0) {
			++len;

			num = num * 10 + 1;
			num %= n;
		}

		cout << len << "\n";
	}

	return 0;
}