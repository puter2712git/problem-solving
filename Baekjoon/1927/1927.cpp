#include <iostream>
#include <queue>

using namespace std;


/// @brief Calculate min heap.
/// @param _heap priority queue sorted by ascending order
/// @param _x operand integer value
void min_heap_calculate(priority_queue<int, vector<int>, greater<int>> &_heap, int _x)
{
  if (_x == 0) {
    if (_heap.empty()) {
      cout << 0 << '\n';
    } else {
      cout << _heap.top() << '\n';
      _heap.pop();
    }

    return;
  }

  _heap.push(_x);
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  priority_queue<int, vector<int>, greater<int>> heap;

  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    min_heap_calculate(heap, x);
  }

  return 0;
}