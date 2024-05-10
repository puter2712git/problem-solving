#include <iostream>
#include <vector>

using namespace std;

int n;
int m;
pair<int, int> target;
vector<vector<int>> relation;
vector<bool> visitFlags;

int relativeCount = -1;

void Dfs(int curr, int rel)
{
	if (curr == target.second) {
		relativeCount = rel;
		return;
	}

	for (int i = 0; i < relation[curr].size(); ++i) {
		int tmp = relation[curr][i];
		if (visitFlags[tmp])
			continue;

		visitFlags[tmp] = true;
		Dfs(relation[curr][i], rel + 1);
		visitFlags[tmp] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	cin >> target.first >> target.second;
	cin >> m;
	relation = vector<vector<int>>(n + 1, vector<int>());
	visitFlags = vector<bool>(n + 1, false);

	for (int i = 0; i < m; ++i) {
		int begin, end;
		cin >> begin >> end;
		relation[begin].push_back(end);
		relation[end].push_back(begin);
	}

	Dfs(target.first, 0);

	cout << relativeCount << "\n";

	return 0;
}