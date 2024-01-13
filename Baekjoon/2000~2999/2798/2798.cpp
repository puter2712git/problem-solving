#include <cstdio>
#include <vector>

using namespace std;


void find_cards(vector<int> &_cards, int sum_of_cards)
{
	int size = _cards.size();
	int sum = 0;
	int min = -1;
	int min_sum = 0;

	/* 0번째 인덱스부터 마지막 인덱스 - 2까지 반복 */
	for (int i = 0; i < size - 2; i++) {
		/* i + 1번째 인덱스부터 마지막 인덱스 - 1까지 반복 */
		for (int j = i + 1; j < size - 1; j++) {
			/* j + 1번째 인덱스부터 마지막 인덱스까지 반복 */
			for (int k = j + 1; k < size; k++) {
				sum = 0;
				sum += _cards[k];
				sum += _cards[j];
				sum += _cards[i];

				/* @sum_of_cards보다 크면 다시 탐색 */
				if (sum > sum_of_cards) {
					continue;
				}

				/* @min에 값이 없거나 현재 카드들의 합이 @min이었을 때의 합보다 더 가깝다면 */
				if (min == -1 || min > sum_of_cards - sum) {
					min = sum_of_cards - sum;
					min_sum = sum;
				}

				/* 원하는 값에 정확히 일치한다면 */
				if (min == 0) {
					printf("%d\n", min_sum);
					return;
				}
			}
		}
	}

	printf("%d\n", min_sum);
	
	return;
}


int main()
{
	int nr_card, sum_of_cards;
	vector<int> cards;

	scanf("%d %d", &nr_card, &sum_of_cards);
	for (int i = 0; i < nr_card; i++) {
		int card;
		scanf("%d", &card);
		cards.push_back(card);
	}

	find_cards(cards, sum_of_cards);

	return 0;
}