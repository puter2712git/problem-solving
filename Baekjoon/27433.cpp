#include <iostream>

using namespace std;

long long factorial(long long n)
{
	if (n == 0) return 1;

	return n * factorial(n - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long N;
	
	cin >> N;
	cout << factorial(N) << "\n";

	return 0;
}