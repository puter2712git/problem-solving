#include <iostream>
#include <map>

using namespace std;

string name;
map<char, int> charCount;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> name;

	int oddCount = 0;
	for (char element : name) {
		if (charCount.find(element) == charCount.end()) {
			charCount.insert({ element, 1 });
			oddCount++;
		} else {
			charCount[element]++;

			if (charCount[element] % 2 == 0) {
				oddCount--;
			} else {
				oddCount++;
			}
		}
	}

	string str;
	char odd = '\0';

	if (oddCount > 1) {
		cout << "I\'m Sorry Hansoo\n";
		return 0;
	} else {

		for (auto iter = charCount.begin(); iter != charCount.end(); iter++) {
			if (iter->second % 2 == 1) {
				odd = iter->first;
			}

			for (int i = 0; i < iter->second / 2; i++) {
				str += iter->first;
			}
		}
	}

	for (int i = 0; i < str.length(); i++) {
		cout << str[i];
	}
	if (odd != '\0') {
		cout << odd;
	}
	for (int i = 0; i < str.length(); i++) {
		cout << str[str.length() - i - 1];
	}

	cout << "\n";

	return 0;
}