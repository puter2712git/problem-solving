/**
 * 백준 10974 모든 순열
 *
 * 1부터 N까지의 수로 이루어진 모든 순열을 출력하는 문제이다.
 * 배열을 순회할 때 해당 원소가 이미 순열에 포함되어 있는지 확인해야 한다.
 */

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int element;
	bool isVisited;
};

vector<Node> nodes;
vector<int> seq;

void PrintSequences(int currLen)
{
	if (currLen == nodes.size())
	{
		for (int element : seq)
		{
			cout << element << " ";
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

		nodes[i].isVisited = true;
		seq[currLen] = nodes[i].element;
		PrintSequences(currLen + 1);

		nodes[i].isVisited = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	seq = vector<int>(n);
	for (int i = 1; i <= n; i++)
	{
		nodes.push_back({i, false});
	}

	PrintSequences(0);

	return 0;
}