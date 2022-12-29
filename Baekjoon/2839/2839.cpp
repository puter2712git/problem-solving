#include <cstdio>
#include <vector>

int main()
{
	/* 인덱스 0 ~ 5까지 초기화 */
	std::vector<int> nr_sugar_bags = { 0, -1, -1, 1, -1, 1 };
	int sugar;

	scanf("%d", &sugar);

	for (int i = 6; i <= sugar; i++) {
		if (nr_sugar_bags[i - 3] == -1 && nr_sugar_bags[i - 5] == -1) {
			nr_sugar_bags.push_back(-1);
		}

		else if (nr_sugar_bags[i - 3] == -1) {
			nr_sugar_bags.push_back(nr_sugar_bags[i - 5] + 1);
		}

		else if (nr_sugar_bags[i - 5] == -1) {
			nr_sugar_bags.push_back(nr_sugar_bags[i - 3] + 1);
		}

		else {
			nr_sugar_bags.push_back(std::min(nr_sugar_bags[i - 3] + 1, nr_sugar_bags[i - 5] + 1));
		}
	}

	printf("%d\n", nr_sugar_bags[sugar]);

	return 0;
}