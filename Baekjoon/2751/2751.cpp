#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	int nr_num;
	vector<int> nums;

	scanf("%d", &nr_num);
	for (int i = 0; i < nr_num; i++) {
		int num;
		scanf("%d", &num);
		nums.push_back(num);
	}

	sort(nums.begin(), nums.end());

	for (int i = 0; i < nr_num; i++) {
		printf("%d\n", nums[i]);
	}

	return 0;
}