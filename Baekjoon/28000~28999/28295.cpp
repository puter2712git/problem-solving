#include <iostream>

using namespace std;

const char DIRECTIONS[4] = { 'N', 'E', 'S', 'W' };
int currIndex;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i < 10; i++) {
		int tmp;
		cin >> tmp;

		if (tmp == 1) {
			currIndex++;
		} else if (tmp == 2) {
			currIndex += 2;
		} else {
			currIndex--;
		}

		if (currIndex < 0)
			currIndex += 4;
	}

	cout << DIRECTIONS[currIndex % 4] << "\n";

	return 0;
}