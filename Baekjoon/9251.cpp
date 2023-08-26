#include <iostream>
#include <string>

using namespace std;

string a, b;
int a_len, b_len;

int len_of_LCNs[1001][1001];

void fill_lens()
{
	a_len = a.length();
	b_len = b.length();

	a = '0' + a;
	b = '0' + b;

	for (int i = 0; i <= a_len; i++) {
		for (int j = 0; j <= b_len; j++) {
			if (i == 0 || j == 0) {
				len_of_LCNs[i][j] = 0;
			}
			else if (a[i] == b[j]) {
				len_of_LCNs[i][j] = len_of_LCNs[i - 1][j - 1] + 1;
			}
			else {
				len_of_LCNs[i][j] = max(len_of_LCNs[i - 1][j], len_of_LCNs[i][j - 1]);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> a;
	cin >> b;

	fill_lens();

	cout << len_of_LCNs[a_len][b_len] << "\n";

	return 0;
}