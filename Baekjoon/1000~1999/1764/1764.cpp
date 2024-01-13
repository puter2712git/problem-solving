#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


/// @brief Input names and print the overlapped.
/// @param _n number of NONE-heard
/// @param _m number of NONE-seen
void print_overlapped(int _n, int _m)
{
  map<string, bool> names;
  vector<string> no_heard_seens;

  for (int i = 0; i < _n + _m; i++) {
    string name;
    cin >> name;

    if (names[name]) {
      no_heard_seens.push_back(name);
      continue;
    }

    names[name] = true;
  }

  sort(no_heard_seens.begin(), no_heard_seens.end());

  cout << no_heard_seens.size() << '\n';
  for (int i = 0; i < no_heard_seens.size(); i++) {
    cout << no_heard_seens[i] << '\n';
  }
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;

  cin >> n >> m;
  print_overlapped(n, m);

  return 0;
}