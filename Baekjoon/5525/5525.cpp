#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int str_len;
	string str;

	cin >> n;
	cin >> str_len;
	cin >> str;

	int answer = 0;

	for (int i = 1; i < str.size(); i++) {
		int cnt = 0;

		if (str[i - 1] == 'I') {
			while (str[i] == 'O' && str[i + 1] == 'I') {
				i += 2;
				cnt++;

				if (cnt == n) {
					cnt--;
					answer++;
				}
			}
		}
	}

	cout << answer << '\n';

	return 0;
}