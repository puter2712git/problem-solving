#include <iostream>

using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int answer;
		bool hasWrong = false;

		for (int j = 1; j <= 10; j++) {
			cin >> answer;
			if (answer != (j - 1) % 5 + 1)
				hasWrong = true;
		}

		if (!hasWrong) {
			cout << i + 1 << "\n";
		}
	}

	return 0;
}