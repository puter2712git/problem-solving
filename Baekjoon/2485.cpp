#include <iostream>
#include <vector>

using namespace std;

vector<int> get_intervals(vector<int> &trees)
{
	vector<int> ret;
	int size = trees.size();

	for (int i = 0; i < size - 1; i++) {
		ret.push_back(trees[i + 1] - trees[i]);
	}

	return ret;
}

int get_GCD(int a, int b)
{
	if (a % b == 0) {
		return b;
	}

	return get_GCD(b, a % b);
}

int get_GCD_of_array(vector<int> &intervals)
{
	int ret = intervals[0];
	int size = intervals.size();

	for (int i = 0; i < size - 1; i++) {
		ret = get_GCD(ret, intervals[i + 1]);
	}

	return ret;
}

int get_tree_count_to_plant(vector<int> &intervals, int GCD)
{
	int ret = 0;
	int size = intervals.size();

	for (int i = 0; i < size; i++) {
		ret += intervals[i] / GCD - 1;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	vector<int> trees;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int tree;
		cin >> tree;
		trees.push_back(tree);
	}

	vector<int> intervals = get_intervals(trees);
	int GCD = get_GCD_of_array(intervals);

	cout << get_tree_count_to_plant(intervals, GCD) << "\n";

	return 0;
}