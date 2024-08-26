#include <iostream>

using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	N--;

	long long count = 1;

	for (int i = N; i > 1; i -= 2) {
		count *= i;
		count %= (1'000'000'000 + 7);
	}

	cout << count << "\n";

	return 0;
}