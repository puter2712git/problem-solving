#include <iostream>
#include <deque>
#include <utility>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	deque<pair<int, int>> d;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		d.push_back({ i + 1, num });
	}

	while (!d.empty()) {
		pair<int, int> curr = d.front();
		d.pop_front();

		cout << curr.first << ' ';

		if (curr.second > 0) curr.second--;

		while (curr.second != 0) {
			if (curr.second < 0) {
				curr.second++;

				d.push_front(d.back());
				d.pop_back();
			}
			else if (curr.second > 0) {
				curr.second--;

				d.push_back(d.front());
				d.pop_front();
			}
		}
	}
	cout << '\n';

	return 0;
}