#include <iostream>

using namespace std;

long long fastMultiply(long long a, long long b, long long divisor)
{
	if (b == 0) return 1;
	if (b == 1) return a % divisor;

	long long tmp = fastMultiply(a, b / 2, divisor);
	
	if (b % 2 == 0) {
		return tmp * tmp % divisor;
	} else {
		return tmp * tmp % divisor * a % divisor;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long a, b, c;
	cin >> a >> b >> c;

	cout << fastMultiply(a, b, c) << "\n";

	return 0;
}