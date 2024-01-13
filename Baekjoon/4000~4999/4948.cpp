#include <iostream>

using namespace std;

bool is_prime(int n)
{
	if (n == 0 || n == 1) return false;
	if (n == 2) return true;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;

	while (true) {
		cin >> n;
		if (n == 0) break;

		int count = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (is_prime(i)) {
				count++;
			}
		}

		cout << count << "\n";
	}

	return 0;
}