#include <iostream>
#include <string>

using namespace std;

string S;
int q;
char a;
int l, r;

int alps[200'000][26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> S;
	for (int i = 0; i < S.length(); i++) {
		if (i != 0) {
			for (int j = 0; j < 26; j++) {
				alps[i][j] = alps[i - 1][j];
			}
		}

		alps[i][S[i] - 'a']++;
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> a >> l >> r;
		
		int start = l == 0 ? 0 : alps[l - 1][a - 'a'];
		int end = alps[r][a - 'a'];

		cout << end - start << "\n";
	}

	return 0;
}