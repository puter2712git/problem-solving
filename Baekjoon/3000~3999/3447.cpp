#include <iostream>
#include <regex>

using namespace std;

string line;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (getline(cin, line)) {
		while (line.find("BUG") != string::npos) {
			line = regex_replace(line, regex("BUG"), "");
		}

		cout << line << "\n";
	}

	return 0;
}