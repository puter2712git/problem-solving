#include <iostream>

using namespace std;

string str;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> str;

	int len = str.length();
	int count = 0;
	for (int i = 0; i < len - 3; i++) {
		if (str.substr(i, 4) == "DKSH") {
			count++;
		}
	}

	cout << count << "\n";

	return 0;
}