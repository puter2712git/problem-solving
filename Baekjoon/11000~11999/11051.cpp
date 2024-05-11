#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> list;
int N, K;

void FillUpList()
{
	list.clear();
	list = vector<vector<int>>(N + 1, vector<int>());

	list[0] = vector<int>(1, 1);

	for (int i = 1; i <= N; ++i) {
		list[i] = vector<int>(i + 1, 0);

		for (int j = 0; j <= i; ++j) {
			if (j == 0 || j == i) {
				list[i][j] = 1;
			} else {
				list[i][j] = list[i - 1][j - 1] + list[i - 1][j];
				list[i][j] %= 10'007;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;
	FillUpList();

	cout << list[N][K] << "\n";

	return 0;
}