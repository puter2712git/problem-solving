#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	map<string, int, greater<string>> entrance;

	cin >> n;
	for (int i = 0; i < n; i++) {
		string name, op;
		cin >> name >> op;

		if (op == "enter") {
			entrance.insert({ name, 0 });
		}
		if (op == "leave") {
			entrance.erase(name);
		}
	}

	for (auto iter = entrance.begin(); iter != entrance.end(); iter++) {
		cout << iter->first << "\n";
	}

	return 0;
}