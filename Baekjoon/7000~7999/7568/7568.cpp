#include <cstdio>
#include <vector>

using namespace std;

int main()
{
  int nr_human;
  scanf("%d", &nr_human);

  vector<pair<int, int>> sizes(nr_human);
  for (int i = 0; i < nr_human; i++) {
    scanf("%d %d", &sizes[i].first, &sizes[i].second);
  }

  /* 덩치 등수를 위한 변수 */
  int rank;

  for (int i = 0; i < nr_human; i++) {
    rank = 1;
    for (int j = 0; j < nr_human; j++) {
      /* 벡터를 순회하며 자신보다 키와 몸무게 모두 큰 사람이 존재하면 @rank를 1 올린다 */
      if (sizes[i].first < sizes[j].first && sizes[i].second < sizes[j].second) {
        rank++;
      }
    }

    printf("%d ", rank);
  }

  return 0;
}