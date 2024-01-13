#include <iostream>

using namespace std;

bool is_prime(long long n)
{
	if (n == 0 || n == 1) return false;
	if (n == 2) return true;

	for (long long i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int test_count;
	long long n;

	cin >> test_count;
	for (int i = 0; i < test_count; i++) {
		cin >> n;

		while (true) {
			if (is_prime(n)) {
				cout << n << "\n";
				break;
			}

			n++;
		}
	}

	return 0;
}