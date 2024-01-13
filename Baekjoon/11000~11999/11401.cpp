#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;

long long getFactorial(long long n)
{
	long long ret = 1;

	for (int i = 1; i <= n; i++) {
		ret = ret * i % P;
	}
	return ret;
}

long long fastMultiply(long long a, long long b)
{
	if (b == 0) return 1;
	if (b == 1) return a % P;

	long long tmp = fastMultiply(a, b / 2);

	if (b % 2 == 0) {
		return tmp * tmp % P;
	} else {
		return tmp * tmp % P * a % P;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long N, K;
	cin >> N >> K;

	cout << getFactorial(N) * fastMultiply(getFactorial(K) % P * getFactorial(N - K) % P, P - 2) % P << "\n";
	return 0;
}