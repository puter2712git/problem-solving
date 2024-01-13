#include <iostream>

using namespace std;

long long get_GCD(long long a, long long b)
{
	if (a % b == 0) {
		return b;
	}

	return get_GCD(b, a % b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long A, B;

	cin >> A >> B;

	cout << (A * B) / get_GCD(A, B) << "\n";

	return 0;
}