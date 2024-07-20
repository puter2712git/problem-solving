#include <iostream>
#include <vector>

using namespace std;

const vector<int> PRIME_NUMBERS = { 2, 3, 5, 7 };

int N;

bool IsPrime(int n)
{
	if (n < 2)
		return false;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}

	return true;
}

void TracePrime(int num, int length)
{
	if (length == N) {
		cout << num << "\n";
		return;
	}

	for (int i = 1; i < 10; i += 2) {
		int tmp = num * 10 + i;

		if (IsPrime(tmp))
			TracePrime(tmp, length + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (auto &num : PRIME_NUMBERS) {
		TracePrime(num, 1);
	}

	return 0;
}