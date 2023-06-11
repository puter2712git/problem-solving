#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int nr_divisor;
	vector<int> divisors;

	cin >> nr_divisor;
	for (int i = 0; i < nr_divisor; i++) {
		int divisor;
		cin >> divisor;
		divisors.push_back(divisor);
	}

	sort(divisors.begin(), divisors.end());

	cout << divisors.front() * divisors.back() << "\n";

	return 0;
}