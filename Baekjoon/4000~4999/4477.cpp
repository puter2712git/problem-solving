#include <iostream>
#include <string>

using namespace std;

int n;

int CheckHero(string name)
{
	int gCount = 0;
	int bCount = 0;

	int len = name.length();
	for (int i = 0; i < len; i++) {
		if (name[i] == 'g' || name[i] == 'G') {
			gCount++;
		} else if (name[i] == 'b' || name[i] == 'B') {
			bCount++;
		}
	}

	if (gCount < bCount) {
		return -1;
	} else if (gCount == bCount) {
		return 0;
	} else {
		return 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	cin.ignore();
	while (n--) {
		string name;
		getline(cin, name);

		switch (CheckHero(name)) {
		case -1:
			cout << name << " is A BADDY" << "\n";
			break;

		case 0:
			cout << name << " is NEUTRAL" << "\n";
			break;

		case 1:
			cout << name << " is GOOD" << "\n";
			break;
		}
	}

	return 0;
}