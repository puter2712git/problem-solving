#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int bit = 0b0;
	int op_count;
	
	cin >> op_count;

	while (op_count--) {
		string op;
		int num;

		cin >> op;

		if (op == "add") {
			cin >> num;

			bit |= (1 << num);
			continue;
		}

		if (op == "remove") {
			cin >> num;

			bit &= ~(1 << num);
			continue;
		}

		if (op == "check") {
			cin >> num;

			if (bit & (1 << num)) {
				cout << '1' << '\n';
			} else {
				cout << '0' << '\n';
			}

			continue;
		}

		if (op == "toggle") {
			cin >> num;

			bit ^= 1 << num;
			continue;
		}

		if (op == "all") {
			bit = (1 << 21) - 1;
			continue;
		}

		if (op == "empty") {
			bit = 0;
			continue;
		}
	}

	return 0;
}