#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int INPUT_COUNT = 5;

void print_column_order(vector<string> target)
{
	int max_len = 0;

	for (int i = 0; i < INPUT_COUNT; i++) {
		if (max_len < target[i].length()) {
			max_len = target[i].length();
		}
	}

	for (int i = 0; i < max_len; i++) {
		for (int j = 0; j < INPUT_COUNT; j++) {
			if (target[j].length() <= i) continue;

			cout << target[j][i];
		}
	}
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<string> strs;
	string str;

	for (int i = 0; i < INPUT_COUNT; i++) {
		cin >> str;
		strs.push_back(str);
	}

	print_column_order(strs);

	return 0;
}