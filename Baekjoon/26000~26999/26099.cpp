#include <iostream>

using namespace std;

long long N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	long long count = 0;
	while (N % 5) {
		N -= 3;
		count++;
	}

	if (N < 0) {
		cout << "-1\n";
	} else {
		count += N / 5;
		cout << count << "\n";
	}

	return 0;
}