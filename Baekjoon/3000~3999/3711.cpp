#include <iostream>
#include <set>
#include <vector>

using namespace std;

int N;
int G;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> G;

		vector<int> ids(G);
		for (int j = 0; j < G; j++) {
			cin >> ids[j];
		}

		int curr = 1;

		while (true) {
			set<int> remainSet;
			int count = 0;

			for (int &id : ids) {
				if (remainSet.find(id % curr) != remainSet.end()) {
					break;
				}

				remainSet.insert(id % curr);
				count++;
			}

			if (count == G)
				break;

			curr++;
		}

		cout << curr << "\n";
	}

	return 0;
}