#include <iostream>

using namespace std;

int get_gcd(int a, int b)
{
	if (b == 0) {
		return a;
	}

	return get_gcd(b, a % b);
}

int get_lcm(int a, int b)
{
	return (a * b) / get_gcd(a, b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	int m, n, x, y;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> m >> n >> x >> y;

		int answer = -1;
		int fin_year = get_lcm(m, n);

		for (int j = x; j <= fin_year; j += m) {
			int tmp_y = j % n;

			if (tmp_y == 0) {
				tmp_y = n;
			}

			if (tmp_y == y) {
				answer = j;
				break;
			}
		}

		cout << answer << '\n';
	}

	return 0;
}