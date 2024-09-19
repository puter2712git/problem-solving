#include <iostream>

using namespace std;

string word;

const char EXCLUDED_CHARACTERS[] = { 'C', 'A', 'M', 'B', 'R', 'I', 'D', 'G', 'E' };

bool IsIncluded(char ch)
{
	for (const auto &c : EXCLUDED_CHARACTERS) {
		if (c == ch)
			return true;
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> word;

	for (char &c : word) {
		if (!IsIncluded(c)) {
			cout << c;
		}
	}
	cout << "\n";

	return 0;
}