#include <cmath>
#include <iostream>

using namespace std;

int T;
int x, y;

int GetCount()
{
	int ret = 0;

	int len = y - x;
	int rt = sqrt(len);
	int power = pow(rt, 2);

	if (power == len) {
		ret = 2 * rt - 1;
	} else {
		ret = 2 * rt;
	}

	if (len > rt * (rt + 1)) {
		ret++;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> x >> y;
		cout << GetCount() << "\n";
	}

	return 0;
}