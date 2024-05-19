#include <iostream>
#include <list>

using namespace std;

int L;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	char letter;

	cin >> L;
	for (int i = 0; i < L; i++) {
		list<char> password;
		list<char>::iterator cursor = password.begin();

		string str;
		cin >> str;

		for (int index = 0; index < str.length(); index++) {
			if (str[index] == '-') {
				if (cursor != password.begin())
					cursor = password.erase(--cursor);
			} else if (str[index] == '<') {
				if (cursor != password.begin())
					cursor--;
			} else if (str[index] == '>') {
				if (cursor != password.end())
					cursor++;
			} else {
				password.insert(cursor, str[index]);
			}
		}

		for (auto element : password)
			cout << element;
		cout << "\n";
	}

	return 0;
}