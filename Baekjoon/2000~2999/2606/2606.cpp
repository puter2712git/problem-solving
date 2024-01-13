#include <iostream>
#include <vector>
#include <utility>

using namespace std;


void find_virused_computer(const vector<vector<int>> &_networks, vector<bool> &_visited, int &_virused, int _nr_computer, int _vertex = 1)
{
  _visited[_vertex] = true;
  _virused++;

  for (int i = 1; i <= _nr_computer; i++) {
    if (_networks[_vertex][i] && !_visited[i]) {
      find_virused_computer(_networks, _visited, _virused, _nr_computer, i);
    }
  }
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int nr_computer;
  int nr_network;
  vector<vector<int>> networks;
  vector<bool> visited;

  cin >> nr_computer;
  cin >> nr_network;

  for (int i = 0; i <= nr_computer; i++) {
    networks.push_back(vector<int>());
    visited.push_back(false);
    for (int j = 0; j <= nr_computer; j++) {
      networks[i].push_back(0);
    }
  }

  for (int i = 0; i < nr_network; i++) {
    int com1, com2;
    cin >> com1 >> com2;
    networks[com1][com2] = 1;
    networks[com2][com1] = 1;
  }

  int virused = -1;
  find_virused_computer(networks, visited, virused, nr_computer);

  cout << virused << '\n';

  return 0;
}