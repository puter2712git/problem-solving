#include <cstdio>
#include <queue>

using namespace std;


int main()
{
	int nr_card;
	queue<int> cards;

	scanf("%d", &nr_card);
	for (int i = 1; i <= nr_card; i++) {
		cards.push(i);
	}

	/* 카드가 한 장만 남았을 때까지 반복 */
	while (cards.size() != 1) {
		/* 맨 앞의 카드를 삭제 */
		cards.pop();
		/* 맨 앞의 카드를 뒤로 보냄 */
		cards.push(cards.front());
		cards.pop();
	}

	printf("%d\n", cards.front());

	return 0;
}