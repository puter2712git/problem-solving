#include <climits>
#include <ctime>
#include <functional>
#include <iostream>
#include <random>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	mt19937 mt((unsigned int)time(NULL));
	uniform_int_distribution<int> uid(0, INT_MAX);
	auto rand = bind(uid, mt);

	for (int i = 0; i < 814; i++) {
		cout << (rand() % 16280) - 8140 << " " << (rand() % 16280) - 8140 << "\n";
	}

	return 0;
}