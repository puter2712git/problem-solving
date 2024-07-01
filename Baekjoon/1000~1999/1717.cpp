#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> parents;

int FindParent(int target)
{
	if (parents[target] != target) {
		parents[target] = FindParent(parents[target]);
	}
	return parents[target];
}

void UnionParent(int a, int b)
{
	int parentA = FindParent(a);
	int parentB = FindParent(b);

	if (parentA < parentB) {
		parents[parentB] = parentA;
	} else {
		parents[parentA] = parentB;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	parents = vector<int>(n + 1);
	for (int i = 0; i <= n; i++) {
		parents[i] = i;
	}

	while (m--) {
		int op;
		int a, b;
		cin >> op >> a >> b;

		switch (op) {
		case 0:
			UnionParent(a, b);
			break;
		case 1:
			if (FindParent(a) == FindParent(b)) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}

	return 0;
}