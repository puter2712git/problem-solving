#include <iostream>

using namespace std;

int N;
string beforeBits;
string afterBits;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	cin >> beforeBits;
	cin >> afterBits;

	if (N % 2 == 0) {
		if (beforeBits == afterBits) {
			cout << "Deletion succeeded\n";
		} else {
			cout << "Deletion failed\n";
		}
	} else {
		string flippedBits = "";
		for (int i = 0; i < beforeBits.length(); i++) {
			if (beforeBits[i] == '0') {
				flippedBits.push_back('1');
			} else {
				flippedBits.push_back('0');
			}
		}

		if (afterBits == flippedBits) {
			cout << "Deletion succeeded\n";
		} else {
			cout << "Deletion failed\n";
		}
	}

	return 0;
}