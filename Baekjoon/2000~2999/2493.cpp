#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;
vector<int> towers;

void Raycast()
{
	stack<pair<int, int>> s;

	for (int i = 1; i <= N; i++) {
		int currTower = towers[i];

		while (!s.empty()) {
			if (currTower < s.top().second) {
				cout << s.top().first << " ";
				break;
			}
			s.pop();
		}

		if (s.empty()) {
			cout << "0 ";
		}
		s.push({ i, currTower });
	}
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	towers = vector<int>(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> towers[i];
	}

	Raycast();

	return 0;
}