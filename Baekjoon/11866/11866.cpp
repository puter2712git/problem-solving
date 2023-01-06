#include <cstdio>
#include <queue>

using namespace std;

/// @brief Print the josephus sequence
/// @param _sequence queue which has continuous natural number (1, 2, ...)
/// @param _k cycle of josphus problem
void print_josephus(queue<int> &_sequence, int _k)
{
  int cycle;
  int temp;
  printf("<");

  while (!_sequence.empty()) {
    cycle = _k - 1;

    while (cycle > 0) {
      cycle--;
      
      temp = _sequence.front();
      _sequence.pop();
      _sequence.push(temp);
    }

    printf("%d", _sequence.front());
    _sequence.pop();

    if (!_sequence.empty()) {
      printf(", ");
    }
  }

  printf(">\n");
}

int main()
{
  int n, k;
  queue<int> sequence;

  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    sequence.push(i);
  }

  print_josephus(sequence, k);

  return 0;
}