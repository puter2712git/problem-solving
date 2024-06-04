#include <iostream>
#include <vector>

using namespace std;

int n;
vector<bool> primeFlags;

void Fill()
{
	primeFlags = vector<bool>(1'000'001, true);
	primeFlags[0] = false;
	primeFlags[1] = false;

	for (int i = 2; i * i <= 1'000'000; i++) {
		if (primeFlags[i]) {
			for (int j = i * i; j <= 1'000'000; j += i) {
				primeFlags[j] = false;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Fill();

	while (true) {
		cin >> n;
		if (n == 0)
			break;

		bool flag = false;

		for (int i = 3; i <= n / 2; i += 2) {
			if (primeFlags[i] && primeFlags[n - i]) {
				cout << n << " = " << i << " + " << n - i << "\n";
				flag = true;
				break;
			}
		}

		if (!flag) {
			cout << "Goldbach\'s conjecture is wrong." << "\n";
		}
	}

	return 0;
}