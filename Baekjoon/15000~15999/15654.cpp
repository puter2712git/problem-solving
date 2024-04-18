#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int element;
	bool isVisited;

	bool operator<(const Node &n) const { return element < n.element; }
};

void PrintPermutations(vector<Node> &nodes, vector<int> &arr, int currLength,
                       int maxLength)
{
	if (currLength == maxLength)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < nodes.size(); i++)
	{
		if (nodes[i].isVisited)
		{
			continue;
		}

		arr[currLength] = nodes[i].element;
		nodes[i].isVisited = true;
		PrintPermutations(nodes, arr, currLength + 1, maxLength);
		nodes[i].isVisited = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	int m;
	vector<Node> nodes;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		nodes.push_back({number, false});
	}

	sort(nodes.begin(), nodes.end(), less<Node>());

	vector<int> arr(m);
	PrintPermutations(nodes, arr, 0, m);

	return 0;
}