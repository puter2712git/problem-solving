#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<pair<int, int>> objs;

int memo[101][100'001];

void fill_memo()
{
	for (int i = 0; i <= N; i++) {
		for (int w = 0; w <= K; w++) {
			if (i == 0 || w == 0) {
				memo[i][w] = 0;
			}
			else if (w < objs[i].first) {
				memo[i][w] = memo[i - 1][w];
			}
			else {
				memo[i][w] = max(objs[i].second + memo[i - 1][w - objs[i].first], memo[i - 1][w]);
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
	objs.push_back({ 0, 0 });
	for (int i = 0; i < N; i++) {
		int weight, value;
		cin >> weight >> value;
		objs.push_back({ weight, value });
	}

	fill_memo();

	cout << memo[N][K] << "\n";

	return 0;
}