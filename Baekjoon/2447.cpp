#include <iostream>

using namespace std;

void print_star(int num, int x, int y)
{
	if ((x / num) % 3 == 1 && (y / num) % 3 == 1) {
		cout << " ";
		return;
	}

	if (num == 1) {
		cout << "*";
		return;
	}

	print_star(num / 3, x, y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			print_star(N, i, j);
		}
		cout << "\n";
	}

	return 0;
}