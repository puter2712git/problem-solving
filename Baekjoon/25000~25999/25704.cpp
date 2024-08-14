#include <iostream>

using namespace std;

int N;
int P;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	cin >> P;

	int discountPrice = 0;
	int discountPercentage = 0;

	if (N >= 15) {
		discountPrice = 2000;
	} else if (N >= 5) {
		discountPrice = 500;
	}

	if (N >= 20) {
		discountPercentage = 25;
	} else if (N >= 10) {
		discountPercentage = 10;
	}

	int cost = min(P - discountPrice, P * (100 - discountPercentage) / 100);
	cout << (cost < 0 ? 0 : cost) << "\n";

	return 0;
}