#include <iostream>
#include <map>
#include <string>

using namespace std;

int test_count;
int clothes_count;

string name, type;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> test_count;

	while (test_count--) {
		map<string, int> clothes_map;
		cin >> clothes_count;
		
		while (clothes_count--) {
			cin >> name >> type;

			if (clothes_map.find(type) == clothes_map.end()) {
				clothes_map.insert({ type, 1 });
			} else {
				clothes_map[type]++;
			}
		}

		int answer = 1;
		for (auto i : clothes_map) {
			answer *= (i.second + 1);
		}

		answer -= 1;
		cout << answer << "\n";
	}

	return 0;
}