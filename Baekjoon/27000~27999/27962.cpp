#include <iostream>

using namespace std;

int N;
string str;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	cin >> str;

	string s, t;
	for (int i = 1; i <= N; i++) {
		s = str.substr(0, i);
		t = str.substr(N - i, i);

		int diffCount = 0;
		for (int j = 0; j < i; j++) {
			if (s[j] != t[j]) {
				diffCount++;
			}
		}

		if (diffCount == 1) {
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";

	return 0;
}