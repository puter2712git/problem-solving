#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	char left;
	char right;
};

int N;
vector<Node> tree;

void PreorderTraversal(char root = 'A')
{
	if (root == '.')
		return;

	cout << root;

	PreorderTraversal(tree[root - 'A'].left);
	PreorderTraversal(tree[root - 'A'].right);
}

void InorderTraversal(char root = 'A')
{
	if (root == '.')
		return;

	InorderTraversal(tree[root - 'A'].left);
	cout << root;
	InorderTraversal(tree[root - 'A'].right);
}

void PostorderTraversal(char root = 'A')
{
	if (root == '.')
		return;

	PostorderTraversal(tree[root - 'A'].left);
	PostorderTraversal(tree[root - 'A'].right);
	cout << root;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	tree = vector<Node>(N, Node());

	for (int i = 0; i < N; i++) {
		char root, l, r;
		cin >> root >> l >> r;

		tree[root - 'A'].left = l;
		tree[root - 'A'].right = r;
	}

	PreorderTraversal();
	cout << "\n";

	InorderTraversal();
	cout << "\n";

	PostorderTraversal();
	cout << "\n";

	return 0;
}