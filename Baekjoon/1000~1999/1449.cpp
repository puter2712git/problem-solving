#include <iostream>
#include <vector>

using namespace std;

int N;
int L;
vector<bool> positions = vector<bool>(1001, false);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		positions[tmp] = true;
	}

	int count = 0;

	for (int i = 1; i <= 1000; i++) {
		if (positions[i]) {
			for (int j = 0; j < L; j++) {
				positions[i + j] = false;
			}
			count++;

			i += L - 1;
		}
	}

	cout << count << "\n";

	return 0;
}