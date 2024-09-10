#include <iostream>
#include <vector>

using namespace std;

const int DIGIT[10][7] = {
	{ 1, 1, 1, 0, 1, 1, 1 },
	{ 0, 0, 1, 0, 0, 1, 0 },
	{ 1, 0, 1, 1, 1, 0, 1 },
	{ 1, 0, 1, 1, 0, 1, 1 },
	{ 0, 1, 1, 1, 0, 1, 0 },
	{ 1, 1, 0, 1, 0, 1, 1 },
	{ 1, 1, 0, 1, 1, 1, 1 },
	{ 1, 0, 1, 0, 0, 1, 0 },
	{ 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 0, 1, 1 },
};

int s;
string n;

void Render(char num, int index)
{
	int number = num - '0';

	if (index == 0 || index == 3 || index == 6) {
		cout << " ";

		for (int i = 0; i < s; i++) {
			if (DIGIT[number][index]) {
				cout << "-";
			} else {
				cout << " ";
			}
		}

		cout << "  ";
	} else {
		if (DIGIT[number][index]) {
			cout << "|";
		} else {
			cout << " ";
		}

		if (index == 1 || index == 4) {
			for (int i = 0; i < s; i++) {
				cout << " ";
			}
		} else {
			cout << " ";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> s >> n;

	for (int i = 0; i < n.length(); i++) {
		Render(n[i], 0);
	}
	cout << "\n";

	for (int i = 0; i < s; i++) {
		for (int j = 0; j < n.length(); j++) {
			Render(n[j], 1);
			Render(n[j], 2);
		}
		cout << "\n";
	}

	for (int i = 0; i < n.length(); i++) {
		Render(n[i], 3);
	}
	cout << "\n";

	for (int i = 0; i < s; i++) {
		for (int j = 0; j < n.length(); j++) {
			Render(n[j], 4);
			Render(n[j], 5);
		}
		cout << "\n";
	}

	for (int i = 0; i < n.length(); i++) {
		Render(n[i], 6);
	}
	cout << "\n";

	return 0;
}