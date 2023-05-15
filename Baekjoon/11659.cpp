#include <iostream>

using namespace std;

void convert_to_sums(int sums[], int nums[], int num_count)
{
	int tmp = 0;

	for (int i = 0; i <= num_count; i++) {
		tmp += nums[i];
		sums[i] = tmp;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int num_count, answer_count;
	int nums[100001];
	int sum_nums[100001];

	cin >> num_count >> answer_count;
	nums[0] = 0;
	for (int i = 1; i <= num_count; i++) {
		cin >> nums[i];
	}

	convert_to_sums(sum_nums, nums, num_count);

	while (answer_count--) {
		int begin, end;
		cin >> begin >> end;

		cout << sum_nums[end] - sum_nums[begin - 1] << '\n';
	}

	return 0;
}