#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> primeNums;

bool IsPrime(int n)
{
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 2; i <= 10000; i++) {
		if (IsPrime(i)) {
			primeNums.push_back(i);
		}
	}

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		pair<int, int> partition;
		cin >> n;

		for (int primeNum : primeNums) {
			if (primeNum > n / 2)
				break;

			if (IsPrime(n - primeNum)) {
				partition.first = primeNum;
				partition.second = n - primeNum;
			}
		}

		cout << partition.first << " " << partition.second << "\n";
	}

	return 0;
}