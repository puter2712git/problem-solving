#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

/// @brief Get the count of the _find in _cards
/// @param _cards vector array
/// @param _find integer to find
/// @return count of the _find
int get_count(vector<int> &_cards, int _find)
{
  int low_index = lower_bound(_cards.begin(), _cards.end(), _find) - _cards.begin();
  int high_index = upper_bound(_cards.begin(), _cards.end(), _find) - _cards.begin();

  return high_index - low_index;
}

int main()
{
  int nr_card;
  vector<int> cards;

  scanf("%d", &nr_card);
  for(int i = 0; i < nr_card; i++) {
    int card;
    scanf("%d", &card);
    cards.push_back(card);
  }

  sort(cards.begin(), cards.end());

  int nr_find;
  vector<int> finds;

  scanf("%d", &nr_find);
  for (int i = 0; i < nr_find; i++) {
    int find;
    scanf("%d", &find);
    finds.push_back(find);
  }

  for (int i = 0; i < nr_find; i++) {
    printf("%d ", get_count(cards, finds[i]));
  }

  return 0;
}