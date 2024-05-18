#include <iostream>

using namespace std;

long long n, m;

int GetCountOfTwo(long long n)
{
	int ret = 0;

	for (long long i = 2; i <= n; i *= 2) {
		ret += n / i;
	}

	return ret;
}

int GetCountOfFive(long long n)
{
	int ret = 0;

	for (long long i = 5; i <= n; i *= 5) {
		ret += n / i;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	int countOfTwo = GetCountOfTwo(n) - GetCountOfTwo(m) - GetCountOfTwo(n - m);
	int countOfFive = GetCountOfFive(n) - GetCountOfFive(m) - GetCountOfFive(n - m);

	cout << (countOfTwo < countOfFive ? countOfTwo : countOfFive) << "\n";

	return 0;
}