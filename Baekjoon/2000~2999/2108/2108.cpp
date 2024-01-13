#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int get_mean(vector<int> &_nums, int _size)
{
	int sum = 0;

	for (int i = 0; i < _size; i++) {
		sum += _nums[i];
	}

	return round((float)sum / _size);
}


int get_median(vector<int> &_nums, int _size)
{
	sort(_nums.begin(), _nums.end());

	/* @_size는 홀수 */
	return _nums[(_size - 1) / 2];
}


int get_mode(vector<int> &_nums, int _size)
{
	/* 최빈값을 구하기 위한 벡터 */
	vector<int> num_count(8001);
	vector<int> max;
	int max_count = 0;
	
	fill(num_count.begin(), num_count.end(), 0);

	for (int i = 0; i < _size; i++) {
		/* @_nums[i]가 음수 */
		if (_nums[i] < 0) {
			num_count[-_nums[i] + 4000]++;

			/* @_nums[i]가 최빈값이라면 */
			if (max_count < num_count[-_nums[i] + 4000]) {
				max_count = num_count[-_nums[i] + 4000];

				max.clear();
				max.push_back(_nums[i]);
			}
			/* @_nums[i]가 최빈값과 count가 같다면 */
			else if (max_count == num_count[-_nums[i] + 4000]) {
				max.push_back(_nums[i]);
			}
		}
		/* @_nums[i]가 양수 */
		else {
			num_count[_nums[i]]++;

			/* @_nums[i]가 최빈값이라면 */
			if (max_count < num_count[_nums[i]]) {
				max_count = num_count[_nums[i]];
				
				max.clear();
				max.push_back(_nums[i]);
			}
			/* @_nums[i]가 최빈값과 count가 같다면 */
			else if (max_count == num_count[_nums[i]]) {
				max.push_back(_nums[i]);
			}
		}
	}

	if (max.size() > 1) {
		sort(max.begin(), max.end());
		return max[1];
	}

	return max[0];
}


int get_range(vector<int> &_nums, int _size)
{
	sort(_nums.begin(), _nums.end());
	return _nums[_size - 1] - _nums[0];
}


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

	printf("%d\n", get_mean(nums, nr_num));
	printf("%d\n", get_median(nums, nr_num));
	printf("%d\n", get_mode(nums, nr_num));
	printf("%d\n", get_range(nums, nr_num));

	return 0;
}