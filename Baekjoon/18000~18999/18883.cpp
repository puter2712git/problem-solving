#include <iostream>

using namespace std;

int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	int num = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << num;
			num++;

			if (j != M - 1) {
				cout << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}