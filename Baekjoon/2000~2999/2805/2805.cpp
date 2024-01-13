#include <cstdio>
#include <vector>

using namespace std;


int get_max_cut_height(vector<int> &_trees, int _need_tree_len, int _max_tree)
{
	int low = 0;
	int top = _max_tree;
	int mid;
	int max = -1;
	long long int tree_len = 0;

	while (low <= top) {
		tree_len = 0;
		mid = (low + top) / 2;

		/* @tree_len에 자른 나무의 길이 할당 */
		for (int i = 0; i < _trees.size(); i++) {
			if (_trees[i] > mid) {
				tree_len += _trees[i] - mid;
			}
		}

		/* @tree_len이 @_need_tree_len보다 작은 경우 */
		if (tree_len < _need_tree_len) {
			top = mid - 1;
		}

		/* @tree_len이 @_need_tree_len보다 크거나 같은 경우 */
		else if (tree_len >= _need_tree_len) {
			low = mid + 1;
			
			/* 현재까지의 @max값을 비교하여 @max를 업데이트 */
			if (max < mid || max == -1) {
				max = mid;
			}
		}
	}

	return max;
}


int main()
{
	int nr_tree, need_tree_len;
	int max_tree = 0;
	vector<int> trees;

	scanf("%d %d", &nr_tree, &need_tree_len);
	for (int i = 0; i < nr_tree; i++) {
		int tree;
		scanf("%d", &tree);
		trees.push_back(tree);

		if (max_tree < tree) {
			max_tree = tree;
		}
	}

	printf("%d\n", get_max_cut_height(trees, need_tree_len, max_tree));

	return 0;
}