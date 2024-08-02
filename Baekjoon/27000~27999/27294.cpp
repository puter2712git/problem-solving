#include <iostream>

using namespace std;

int T;
int S;

bool IsLunch() { return T >= 12 && T <= 16; }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T >> S;

	if (IsLunch() && S == 0) {
		cout << "320\n";
	} else {
		cout << "280\n";
	}

	return 0;
}