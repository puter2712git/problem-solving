#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// @brief Return the count of the conference.
/// @param _conferences vector<pair<int, int>>
/// @return count of the conference
int get_conference_count(vector<pair<int, int>> &_conferences)
{
  int size = _conferences.size();

  int end_time = _conferences[0].first;
  int count = 1;

  for (int i = 1; i < size; i++) {
    if (_conferences[i].second >= end_time) {
      end_time = _conferences[i].first;
      count++;
    }
  }

  return count;
}


int main()
{
  int n;
  vector<pair<int, int>> conferences;

  cin >> n;
  for (int i = 0; i < n; i++) {
    int start, end;
    cin >> start >> end;
    conferences.push_back({ end, start });
  }

  sort(conferences.begin(), conferences.end());

  cout << get_conference_count(conferences) << '\n';

  return 0;
}