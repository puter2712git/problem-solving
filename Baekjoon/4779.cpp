#include <iostream>
#include <cmath>

using namespace std;

void cantor(int num)
{
	if (num == 0) {
		cout << "-";
		return;
	}

	cantor(num - 1);
	for (int i = 0; i < pow(3, num - 1); i++) cout << " ";
	cantor(num - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;

	while (true) {
		cin >> N;
		if (cin.eof()) break;
		
		cantor(N);
		cout << "\n";
	}

	return 0;
}