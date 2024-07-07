#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;
vector<vector<int>> tree;

int root;
int deleteNode;

int GetLeafNodeCount()
{
	int ret = 0;

	stack<int> s;
	s.push(root);

	while (!s.empty()) {
		int curr = s.top();
		s.pop();

		if (curr == deleteNode)
			continue;
		if (tree[curr].size() == 0)
			ret++;

		for (const auto &next : tree[curr]) {
			s.push(next);
			if (next == deleteNode && tree[curr].size() == 1) {
				ret++;
			}
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	tree = vector<vector<int>>(N, vector<int>());

	for (int i = 0; i < N; i++) {
		int parent;
		cin >> parent;

		if (parent == -1) {
			root = i;
			continue;
		}

		tree[parent].push_back(i);
	}

	cin >> deleteNode;
	cout << GetLeafNodeCount() << "\n";

	return 0;
}