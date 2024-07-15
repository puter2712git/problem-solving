#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> relation;
vector<bool> visitFlags;

bool hasRelation = false;

void Trace(int curr, int count = 0)
{
	if (count == 4) {
		hasRelation = true;
		return;
	}

	visitFlags[curr] = true;

	for (const auto &p : relation[curr]) {
		if (visitFlags[p])
			continue;

		Trace(p, count + 1);
		visitFlags[p] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	relation = vector<vector<int>>(N, vector<int>());
	visitFlags = vector<bool>(N, false);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		relation[a].push_back(b);
		relation[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		Trace(i);
		visitFlags[i] = false;

		if (hasRelation) {
			cout << 1 << "\n";
			return 0;
		}
	}

	cout << 0 << "\n";
	return 0;
}