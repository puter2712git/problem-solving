#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int H;

	cin >> H;

	if (H == 1) {
		cout << "2" << "\n";
	}
	else {
		cout << "1" << "\n";
	}

	return 0;
}