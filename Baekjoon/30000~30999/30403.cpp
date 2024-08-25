#include <iostream>
#include <vector>

using namespace std;

const int RAINBOW_INDICES[] = { 'r' - 'a', 'o' - 'a', 'y' - 'a', 'g' - 'a', 'b' - 'a', 'i' - 'a', 'v' - 'a' };

int N;
string text;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	cin >> text;

	vector<bool> hasLowercase(26, false);
	vector<bool> hasUppercase(26, false);

	for (int i = 0; i < N; i++) {
		char c = text[i];

		if (isupper(c)) {
			hasUppercase[c - 'A'] = true;
		} else {
			hasLowercase[c - 'a'] = true;
		}
	}

	bool canMakeUppercase = true;
	bool canMakeLowercase = true;

	for (int index : RAINBOW_INDICES) {
		if (!hasUppercase[index]) {
			canMakeUppercase = false;
			break;
		}
	}
	for (int index : RAINBOW_INDICES) {
		if (!hasLowercase[index]) {
			canMakeLowercase = false;
			break;
		}
	}

	if (canMakeUppercase && canMakeLowercase) {
		cout << "YeS\n";
	} else if (canMakeUppercase) {
		cout << "YES\n";
	} else if (canMakeLowercase) {
		cout << "yes\n";
	} else {
		cout << "NO!\n";
	}

	return 0;
}