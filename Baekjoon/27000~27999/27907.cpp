#include <iostream>

using namespace std;

long long A, B;

long long GetGCD(long long n, long long m)
{
	if (m == 0)
		return n;
	else
		return GetGCD(m, n % m);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> A >> B;
	int gcd = GetGCD(A, B);

	for (int i = 0; i < gcd; i++) {
		cout << 1;
	}
	cout << "\n";

	return 0;
}