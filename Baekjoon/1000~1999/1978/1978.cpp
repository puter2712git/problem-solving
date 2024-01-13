#include <cstdio>
#include <vector>

using namespace std;


void fill_eratos(vector<bool> &_eratos)
{
	for (int i = 2; i * i < 1001; i++) {
		for (int j = i * i; j < 1001; j += i) {
			_eratos[j] = false;
		}
	}

	return;
}


int main()
{
	int nr_num;
	scanf("%d", &nr_num);

	vector<int> nums(nr_num);
	vector<bool> eratos(1001);
	fill(eratos.begin(), eratos.end(), true);
	eratos[1] = false;

	for (int i = 0; i < nr_num; i++) {
		scanf("%d", &nums[i]);
	}

	fill_eratos(eratos);

	int count = 0;

	for (int i = 0; i < nr_num; i++) {
		if (eratos[nums[i]]) {
			count++;
		}
	}

	printf("%d", count);

	return 0;
}